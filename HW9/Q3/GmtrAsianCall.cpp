//
//  GmtrAsianCall.cpp
//  Assignment9_q3
//
//  Created by Elizabeth Zhang on 3/27/18.
//  Copyright © 2018 Elizabeth Zhang. All rights reserved.
//

#include "GmtrAsianCall.hpp"

#include <cmath>
#include "EurCall.hpp"

double GmtrAsianCall::Payoff(SamplePath& S)
{
	double Prod=1.0;
	for (int i=0; i<m; i++)
	{
		Prod=Prod*S[i];
	}
	if (pow(Prod,1.0/m)<K) return 0.0;
	return pow(Prod,1.0/m)-K;
}

double GmtrAsianCall::PriceByBSFormula(BSModel Model)
{
	double a = exp(-Model.r*T)*Model.S0*exp(
											(m+1.0)*T/(2.0*m)*(Model.r+Model.sigma*Model.sigma
															   *((2.0*m+1.0)/(3.0*m)-1.0)/2.0));
	double b = Model.sigma*sqrt((m+1.0)*(2.0*m+1.0)/(6.0*m*m));
	EurCall G(T, K);
	Price = G.PriceByBSFormula(a,b,Model.r);
	return Price;
}

double GmtrAsianCall::DeltaByBSFormula(BSModel Model)
{
	double a = exp(-Model.r*T)*Model.S0*exp(
											(m+1.0)*T/(2.0*m)*(Model.r
															   +Model.sigma*Model.sigma
															   *((2.0*m+1.0)/(3.0*m)-1.0)/2.0));
	double b = Model.sigma
	*sqrt((m+1.0)*(2.0*m+1.0)/(6.0*m*m));
	EurCall G(T, K);
	delta = G.DeltaByBSFormula(a,b,Model.r)*a/Model.S0;
	return delta;
}
