#include <iostream>

double calcEV(double truth_probability, double pred_payout)
{
	double estimated_value = (truth_probability*pred_payout) - 1.0;
	return estimated_value;
	
}

double getTruthOdds(int line_yes, int line_no, bool yes = true)
{
	double yes_prob, no_prob;
	if (line_yes < 0)
	{
		yes_prob = (-1.0 * line_yes)/(-1.0*line_yes + 100);
	}
	else
	{
		yes_prob = (1.0*100)/(100+line_yes);
	}
	if (line_no < 0)
	{
		no_prob = (-1.0 * line_no)/(-1.0*line_no + 100);
	}
	else
	{
		no_prob = (1.0*100)/(100+line_no);
	}

	if (yes_prob + no_prob > 1.0)
	{
		double vig = yes_prob + no_prob;
		yes_prob /= vig;
		no_prob /= vig;
	}


	if (yes) { return yes_prob; }
	return no_prob;
}

int main()
{
	int line_yes, line_no;
	int prob;
	std::cout << "Input the sportsbook odds for your team winning, and then the other team winning.\n";
	std::cin >> line_yes >> line_no;
	std::cout << "Input the kalshi price for yes to your team winning (in cents). \n";
	std::cin >> prob;

	double payout = 100.0/prob;
	std::cout << "The percent loss/gain you get from investing in yes (estimated value) is " << calcEV(getTruthOdds(line_yes,line_no),payout) << "\n";

	return 0;
}
