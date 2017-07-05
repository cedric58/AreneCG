#pragma once

static std::vector<std::string> split(std::string str, char sep = ' ')
{
	std::vector<std::string> ret;

	std::istringstream stm(str);
	std::string token;
	while (std::getline(stm, token, sep)) ret.push_back(token);

	return ret;
}