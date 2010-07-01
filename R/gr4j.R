## hydromad: Hydrological Modelling and Analysis of Data
##
## Copyright (c) Felix Andrews <felix@nfrac.org>
##

gr4j.sim <-
    function(DATA,
             x1, etmult = 1, S_0 = 0, 
             return_state = FALSE)
{
    stopifnot(c("P","E") %in% colnames(DATA))
    ## check values
    stopifnot(x1 >= 0)
    stopifnot(etmult >= 0)
    stopifnot(S_0 >= 0)
    stopifnot(S_0 <= 1)

    inAttr <- attributes(DATA[,1])
    DATA <- as.ts(DATA)
    P <- DATA[,"P"]
    E <- DATA[,"E"] * etmult

    ## skip over missing values (maintaining the state S)
    bad <- is.na(P) | is.na(E)
    P[bad] <- 0
    E[bad] <- 0
    COMPILED <- (hydromad.getOption("pure.R.code") == FALSE)
    if (COMPILED) {
        ans <- .C(sma_gr4j,
                as.double(P),
                as.double(E),
                as.integer(NROW(DATA)),
                as.double(x1),
                as.double(S_0),
                U = double(NROW(DATA)),
                S = double(NROW(DATA)),
                ET = double(NROW(DATA)),
                NAOK=FALSE, DUP=FALSE, PACKAGE="hydromad")
        U <- ans$U
        S <- ans$S
        ET <- ans$ET
    } else {
        ## implementation in R for cross-checking (slow)
        U <- S <- ET <- P
        S_prev <- S_0 * x1
        for (t in seq(1, length(P))) {
            Pn <- max(P[t] - E[t], 0)
            En <- max(E[t] - P[t], 0)
            St_x1 <- S_prev / x1
            ## production
            Ps <- 0
            ET[t] <- 0
            if (Pn > 0) {
                ## part of Pn fills the production store
                Ps <- ( x1 * (1 - St_x1^2) * tanh(Pn/x1) /
                       (1 + St_x1 * tanh(Pn/x1)) )
            } else {
                ## actual evapo-transpiration
                ET[t] <- ( S[t] * (2 - St_x1) * tanh(En/x1) /
                          (1 + (1 - St_x1) * tanh(En/x1)) )
            }
            S[t] <- S_prev - ET[t] + Ps
            ## percolation leakage
            perc <- S[t] * ( 1 - (1 + ((4/9) * St_x1)^4)^(-0.25) )
            S[t] <- S[t] - perc
            U[t] <- perc + (Pn - Ps)
            S_prev <- S[t]
        }
    }
    
    attributes(U) <- inAttr
    ## re-insert missing values
    U[bad] <- NA
    ans <- U
    if (return_state) {
        attributes(S) <- attributes(ET) <- attributes(U)
        ans <- cbind(U=U, S=S, ET=ET)
    }
    return(ans)
}

gr4j.ranges <- function()
    list(x1 = c(100, 1200),
         etmult = 1)

gr4jrouting.sim <-
    function(U, x2, x3, x4, R_0 = 0,
             return_components = FALSE,
             epsilon = hydromad.getOption("sim.epsilon"))
{
    ## check values
    stopifnot(is.numeric(x2))
    stopifnot(x3 >= 0)
    stopifnot(x4 >= 0.5)
    stopifnot(R_0 >= 0)
    stopifnot(R_0 <= 1)

    inAttr <- attributes(U)
    U <- as.ts(U)

    n <- ceiling(x4)
    m <- ceiling(x4 * 2)

    ## S-curves: cumulative proportion of input with time
    SH1 <- (1:x4 / x4) ^ (5/2)
    SH2 <- c(0.5 * SH1,
             1 - 0.5 * (2 - floor(x4+1):(2*x4) / x4) ^ (5/2)
             )
    ## unit hydrographs
    UH1 <- diff(SH1)
    UH2 <- diff(SH2)

    ## skip over missing values (maintaining the state)
    bad <- is.na(U)
    U[bad] <- 0
    
    Q9 <- filter(0.9 * U, UH1, sides = 1)
    Q1 <- filter(0.1 * U, UH2, sides = 1)

    ## fill in values undefined by UH filter
    Q9[seq_along(UH1)] <- 0
    Q1[seq_along(UH2)] <- 0
    bad[seq_along(UH2)] <- TRUE
    
    COMPILED <- (hydromad.getOption("pure.R.code") == FALSE)
    if (COMPILED) {
        ans <- .C(routing_gr4j,
                  as.double(Q9),
                  as.double(Q1),
                  as.integer(length(U)),
                  as.double(x2),
                  as.double(x3),
                  as.double(R_0),
                  Qr = double(length(U)),
                  Qd = double(length(U)),
                  R = double(length(U)),
                  NAOK=FALSE, DUP=FALSE, PACKAGE="hydromad")
        Qr <- ans$Qr
        Qd <- ans$Qd
        R <- ans$R
    } else {
        ## implementation in R for cross-checking (slow)
        Qd <- Qr <- R <- U
        R_prev <- R_0 * x3
        for (t in seq(1, length(U))) {
            Rt_x3 <- R_prev / x3
            ## groundwater exchange term
            F <- x2 * Rt_x3 ^ (7/2)
            ## reservoir level
            R[t] <- max(0, R_prev + Q9[t] + F)
            ## outflow of reservoir
            Qr[t] <- R[t] * ( 1 - (1 + Rt_x3^4)^(-0.25) )
            R[t] <- R[t] - Qr[t]
            ## other store
            Qd[t] <- max(0, Q1[t] + F)
            R_prev <- R[t]
        }
    }

    ## zap simulated values smaller than epsilon
    Qr[Qr < epsilon] <- 0
    Qd[Qd < epsilon] <- 0
    
    attributes(Qr) <- attributes(Qd) <- attributes(R) <- inAttr
    
    ## re-insert missing values
    Qr[bad] <- NA
    Qd[bad] <- NA
    
    if (return_components) {
        return(cbind(Xr = Qr, Xd = Qd, R = R))
    } else {
        return(Qr + Qd)
    }
}

gr4jrouting.ranges <- function()
    list(x2 = c(-5, 3),
         x3 = c(20, 300),
         x4 = c(1.1, 2.9))