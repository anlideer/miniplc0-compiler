#include "catch2/catch.hpp"
#include "tokenizer/tokenizer.h"
#include "fmt/core.h"

#include <sstream>
#include <vector>

// 下面是示例如何书写测试用例
TEST_CASE("Test hello world.", "basic") {
	
	std::string input = 
		"begin\n"
		"	var a = 1;\n"
		"	const b = 1\n"
		"	print(a+b);\n"
		"end\n";
	std::stringstream ss;
	ss.str(input);
	miniplc0::Tokenizer tkz(ss);
	std::vector<miniplc0::Token> output = {};
	auto result = tkz.AllTokens();
	if (result.second.has_value()) {
		FAIL();
	}
	REQUIRE( (result.first == output) );
	
}

// try 1 try
TEST_CASE("Test redefine.", "basic")
{
	std::string input = 
	"begin\n"
	"	var a = 1;\n"
	"	var b = 2;\n"
	"	b = 3;\n";
	"	var a = 2;\n"
	"end\n";
	std::stringstream ss;
	ss.str(input);
	miniplc0::Tokenizer tkz(ss);
	std::vector<miniplc0::Token> output = {};
	auto result = tkz.AllTokens();
	if (result.second.has_value()) {
		FAIL();
	}
	REQUIRE( (result.first == output) );
}