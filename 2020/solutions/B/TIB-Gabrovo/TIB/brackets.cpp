#include <bits/stdc++.h>

#define ENDL "\r\n"
#define EXTRACT(m) \
	auto a = std::stold(m[1]); \
	auto b = std::stold(m[3]);

namespace {
	typedef std::string expression;
	typedef std::pair<int, int> bracket_pair;
	
	typedef std::vector<std::smatch> matches;
	typedef std::function<std::string(std::smatch)> mapper;

	expression numerical_expr; // Expression with substituted values
	std::vector<bracket_pair> brackets;

	std::regex brackets_regex(R"(\(([^\(\)]+)\))", std::regex::optimize);

	expression number_pattern = R"(([\+\-]?\d+(\.\d+)?))";
	
	std::regex addition_regex;
	std::regex subtract_regex;
	std::regex multiply_regex;
	std::regex division_regex;

	auto build_regex(const expression& s) -> std::regex {
		return std::regex(number_pattern + s + number_pattern,
				  std::regex::optimize);
	}

	auto dtos(long double d) -> expression {
		auto str = std::to_string(d);
		return d >= 0 ? "+" + str : str;
	}

	auto replace(const expression& s,
	             const std::regex& r,
		     const mapper&     f) 
		-> expression {
		auto res = std::string();
		auto curr = s;
		std::smatch m;

		auto flag = false;

		while(std::regex_search(curr, m, r)) {
			res += m.prefix();
			res += f(m);

			curr = m.suffix();		
		
			flag = true;
		}

		res += curr;
		return flag ? replace(res, r, f) : res;
	}

	auto eval(expression r) -> expression {
   		r = replace(r, brackets_regex, 
				[&](const auto& p) {	
					return eval(p[1]);
				});

		r = replace(r, multiply_regex, 
				[&](const auto& p) {
					EXTRACT(p);
					return dtos(a * b);
				});

		r = replace(r, division_regex,
				[&](const auto& p) {
					EXTRACT(p);
					return dtos(a / b);
				});

		r = replace(r, addition_regex,
				[&](const auto& p) {
					EXTRACT(p);
					return dtos(a + b);
				});

		r = replace(r, subtract_regex,
				[&](const auto& p) {
					EXTRACT(p);
					return dtos(a - b);
				});
		
		return r;
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	addition_regex = build_regex(R"(\+)");
	subtract_regex = build_regex(R"(\-)");
	multiply_regex = build_regex(R"(\*)");
	division_regex = build_regex(R"(\/)");

	std::string expr;
	std::cin >> expr;

	// Parsing
	auto v = 1;
	std::stack<int> s;

	for(auto i = 0; i < expr.size(); ++i) {
		auto val = expr[i];
		auto app = false;

		switch(val) {
		case '(':
			s.push(i);
			break;
		case ')':
			brackets.emplace_back(i, s.top());
			s.pop();
			break;
		case '&':
			app = true;
			break;
		}

		if(app) {
			numerical_expr += std::to_string(v++);
		} else {
			numerical_expr += val;
		}
	}

	std::cout << numerical_expr << ENDL;

	std::reverse(brackets.begin(), brackets.end());

	// Iteratively remove all brackets and re-evaluate
	// If the solution doesn't change, the brackets were unnecessary
	// If the solution changes, they were necessary and we stop
	auto last_sol = expr;
	auto last_num = numerical_expr;
	auto last_val = eval(numerical_expr);
	auto last_2   = std::numeric_limits<int>::max();
	auto offset   = 0;

	for(auto& val : brackets) {
		auto idx_1 = val.first;	
		auto idx_2 = val.second;

		// If last bracket removal shifted the rest	
		if(last_2 < idx_2) {
			++offset;
		}
		
		idx_1 -= offset;
		idx_2 -= offset;
	
		// Remove the brackets
		auto curr_num = last_num;
		curr_num.erase(curr_num.begin() + idx_1);
		curr_num.erase(curr_num.begin() + idx_2);

		// Re-evaluate
		auto curr_val = eval(curr_num);

		// Compare
		if(curr_val == last_val) {
			// Continue removing brackets
			last_sol.erase(last_sol.begin() + idx_1);
			last_sol.erase(last_sol.begin() + idx_2);
			
			last_num = curr_num;
			last_val = curr_val;
			last_2   = idx_2;
		} else {
			// Stop
			break;
		}
	}

	std::cout << last_sol << ENDL;

	return 0;
}
