#include "OppParser.h"
#include <fstream>
#include <sstream>
#include <chrono>
#include <iomanip>
using namespace OPP_PARSER_NAMESPACE;


std::string ReadTextFile(const std::string& path) 
{
	std::ifstream stream(path);
	if (!stream.good())
		return "";
	std::stringstream sstr;
	sstr << stream.rdbuf();
	stream.close();
	return sstr.str();
}

int main() 
{
#if 0
	while (true) 
	{
		std::string path;
		std::getline(std::cin, path);
		if (path == "cls") 
		{
			system("cls");
			continue;
		}
		std::string source = ReadTextFile(path);
		auto old_time = std::chrono::high_resolution_clock::now();
		Lexer parser(source, NativeLanguageDialect::Cpp);
		auto delta = std::chrono::high_resolution_clock::now() - old_time;
		auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(delta);
		std::cout << "Parsing Took : " << ms.count() << "ms.\n";
		int index = 0;
		for (auto& token : parser.Tokens()) 
		{
			std::cout << "[ " << std::setw(3) << index << " ] ";
			std::cout << std::setw(24) << std::left << token.value;
			std::cout << "[ " << std::setw(3) << token.location.Line << " : " << std::setw(3) << token.location.Collumn << " ] ";
			std::cout << "Nr = " << ((token.value_type == ValueType::Number) ? "True " : "False ");
			if (token.value_type == ValueType::Number) {
				double value = 0;
				std::cout << " Value = ";
				token.number_format.ParseToBinaryNumber(token.value, value);
				std::cout << value;
			}
			std::cout << "\n";
			index++;
		}
	}
#endif

	while (true) 
	{
		std::string line;
		std::getline(std::cin, line);
		Lexer lexer(line, NativeLanguageDialect::Cpp);
		Parser parser(lexer);

		const std::vector<TokenMatchTemplate> templates =
		{
			TokenMatchTemplate::MatchPunctuation(NativeLanguagePunctuationID::OpenSquare),
			TokenMatchTemplate::MatchValue(ValueType::Word, ""),
			TokenMatchTemplate::MatchPunctuation(NativeLanguagePunctuationID::Comma),
			TokenMatchTemplate::MatchValue(ValueType::String, ""),
			TokenMatchTemplate::MatchPunctuation(NativeLanguagePunctuationID::ClosedSquare)
		};

		if (parser.TryMatch(templates)) 
		{
			Token t;
			parser.Skip(1);
			parser.Next(t);
			std::cout << t.value << "\n";
			parser.Skip(t, 1);
			std::cout << t.value << "\n";
		}
		else 
		{
			std::cout << "No match\n";
		}
	}
}