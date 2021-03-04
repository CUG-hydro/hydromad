// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// hbv_sim
DataFrame hbv_sim(NumericVector P, NumericVector E, NumericVector Tavg, double tt, double cfmax, double sfcf, double cfr, double cwh, double fc, double lp, double beta, bool initialise_sm);
RcppExport SEXP _hydromad_hbv_sim(SEXP PSEXP, SEXP ESEXP, SEXP TavgSEXP, SEXP ttSEXP, SEXP cfmaxSEXP, SEXP sfcfSEXP, SEXP cfrSEXP, SEXP cwhSEXP, SEXP fcSEXP, SEXP lpSEXP, SEXP betaSEXP, SEXP initialise_smSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector >::type P(PSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type E(ESEXP);
    Rcpp::traits::input_parameter< NumericVector >::type Tavg(TavgSEXP);
    Rcpp::traits::input_parameter< double >::type tt(ttSEXP);
    Rcpp::traits::input_parameter< double >::type cfmax(cfmaxSEXP);
    Rcpp::traits::input_parameter< double >::type sfcf(sfcfSEXP);
    Rcpp::traits::input_parameter< double >::type cfr(cfrSEXP);
    Rcpp::traits::input_parameter< double >::type cwh(cwhSEXP);
    Rcpp::traits::input_parameter< double >::type fc(fcSEXP);
    Rcpp::traits::input_parameter< double >::type lp(lpSEXP);
    Rcpp::traits::input_parameter< double >::type beta(betaSEXP);
    Rcpp::traits::input_parameter< bool >::type initialise_sm(initialise_smSEXP);
    rcpp_result_gen = Rcpp::wrap(hbv_sim(P, E, Tavg, tt, cfmax, sfcf, cfr, cwh, fc, lp, beta, initialise_sm));
    return rcpp_result_gen;
END_RCPP
}
// hbvrouting_sim
DataFrame hbvrouting_sim(NumericVector U, double perc, double uzl, double k0, double k1, double k2, NumericVector wi, int n_maxbas, double initial_lz);
RcppExport SEXP _hydromad_hbvrouting_sim(SEXP USEXP, SEXP percSEXP, SEXP uzlSEXP, SEXP k0SEXP, SEXP k1SEXP, SEXP k2SEXP, SEXP wiSEXP, SEXP n_maxbasSEXP, SEXP initial_lzSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector >::type U(USEXP);
    Rcpp::traits::input_parameter< double >::type perc(percSEXP);
    Rcpp::traits::input_parameter< double >::type uzl(uzlSEXP);
    Rcpp::traits::input_parameter< double >::type k0(k0SEXP);
    Rcpp::traits::input_parameter< double >::type k1(k1SEXP);
    Rcpp::traits::input_parameter< double >::type k2(k2SEXP);
    Rcpp::traits::input_parameter< NumericVector >::type wi(wiSEXP);
    Rcpp::traits::input_parameter< int >::type n_maxbas(n_maxbasSEXP);
    Rcpp::traits::input_parameter< double >::type initial_lz(initial_lzSEXP);
    rcpp_result_gen = Rcpp::wrap(hbvrouting_sim(U, perc, uzl, k0, k1, k2, wi, n_maxbas, initial_lz));
    return rcpp_result_gen;
END_RCPP
}
// hbv_pet
NumericVector hbv_pet(DateVector dates, NumericVector Tavg, NumericVector PET, NumericVector Tmean, double cet);
RcppExport SEXP _hydromad_hbv_pet(SEXP datesSEXP, SEXP TavgSEXP, SEXP PETSEXP, SEXP TmeanSEXP, SEXP cetSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< DateVector >::type dates(datesSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type Tavg(TavgSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type PET(PETSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type Tmean(TmeanSEXP);
    Rcpp::traits::input_parameter< double >::type cet(cetSEXP);
    rcpp_result_gen = Rcpp::wrap(hbv_pet(dates, Tavg, PET, Tmean, cet));
    return rcpp_result_gen;
END_RCPP
}
// simhyd_sim
DataFrame simhyd_sim(NumericVector P, NumericVector E, double INSC, double COEFF, double SQ, double SMSC, double SUB, double CRAK, double K, double GWt0, double SMSt0);
RcppExport SEXP _hydromad_simhyd_sim(SEXP PSEXP, SEXP ESEXP, SEXP INSCSEXP, SEXP COEFFSEXP, SEXP SQSEXP, SEXP SMSCSEXP, SEXP SUBSEXP, SEXP CRAKSEXP, SEXP KSEXP, SEXP GWt0SEXP, SEXP SMSt0SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector >::type P(PSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type E(ESEXP);
    Rcpp::traits::input_parameter< double >::type INSC(INSCSEXP);
    Rcpp::traits::input_parameter< double >::type COEFF(COEFFSEXP);
    Rcpp::traits::input_parameter< double >::type SQ(SQSEXP);
    Rcpp::traits::input_parameter< double >::type SMSC(SMSCSEXP);
    Rcpp::traits::input_parameter< double >::type SUB(SUBSEXP);
    Rcpp::traits::input_parameter< double >::type CRAK(CRAKSEXP);
    Rcpp::traits::input_parameter< double >::type K(KSEXP);
    Rcpp::traits::input_parameter< double >::type GWt0(GWt0SEXP);
    Rcpp::traits::input_parameter< double >::type SMSt0(SMSt0SEXP);
    rcpp_result_gen = Rcpp::wrap(simhyd_sim(P, E, INSC, COEFF, SQ, SMSC, SUB, CRAK, K, GWt0, SMSt0));
    return rcpp_result_gen;
END_RCPP
}
