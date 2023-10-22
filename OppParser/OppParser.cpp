#include "OppParser.h"
#include  <algorithm>
#include <cmath>
#include <sstream>
namespace OPP_PARSER_NAMESPACE 
{
#pragma region HELPER_FUNCTIONS

	bool cmp_separator(const Punctuation& a, const Punctuation& b) { return a.Value().length() > b.Value().length(); }
	bool cmp_keyword(const Keyword& a, const Keyword& b) { return a.Value().length() > b.Value().length(); }
	bool cmp_number_format(const NumberFormat& a, const NumberFormat& b) 
	{ 
		return (a.Prefix().length() + a.Sufix().length() + a.Point()) > (b.Prefix().length() + b.Sufix().length() + a.Point());
	}
#pragma endregion
#pragma region NATIVE_LANGUAGES
	DialectInfo native_language_dialects[] =
	{
		//C
		{ {}, {} },
		//C++
		{
			//Separators
			{
				{"{", NativeLanguagePunctuationID::OpenCurly},
				{"}", NativeLanguagePunctuationID::ClosedCurly},
				{"[", NativeLanguagePunctuationID::OpenSquare},
				{"]", NativeLanguagePunctuationID::ClosedSquare},
				{"#", NativeLanguagePunctuationID::Hash},
				{"##", NativeLanguagePunctuationID::DoubleHash},
				{"(", NativeLanguagePunctuationID::OpenParen},
				{")", NativeLanguagePunctuationID::ClosedParen},
				{";", NativeLanguagePunctuationID::SemiColon},
				{":", NativeLanguagePunctuationID::Colon},
				{"...", NativeLanguagePunctuationID::Expand},
				{"?", NativeLanguagePunctuationID::QuestionMark},
				{"::", NativeLanguagePunctuationID::DoubleColon},
				{".", NativeLanguagePunctuationID::Dot},
				{".*", NativeLanguagePunctuationID::DotStar},
				{"->", NativeLanguagePunctuationID::RightArrow},
				{"->*", NativeLanguagePunctuationID::RightArrowStar},
				{"~", NativeLanguagePunctuationID::Grave},
				{"!", NativeLanguagePunctuationID::Exclamation},
				{"+", NativeLanguagePunctuationID::Plus},
				{"-", NativeLanguagePunctuationID::Minus},
				{"*", NativeLanguagePunctuationID::Star},
				{"/", NativeLanguagePunctuationID::Slash},
				{"%", NativeLanguagePunctuationID::Percent},
				{"^", NativeLanguagePunctuationID::Caret},
				{"&", NativeLanguagePunctuationID::And},
				{"|", NativeLanguagePunctuationID::Or},
				{"=", NativeLanguagePunctuationID::Equal},
				{"+=", NativeLanguagePunctuationID::PlusEqual},
				{"-=", NativeLanguagePunctuationID::MinusEqual},
				{"*=", NativeLanguagePunctuationID::StarEqual},
				{"/=", NativeLanguagePunctuationID::SlashEqual},
				{"%=", NativeLanguagePunctuationID::PercentEqual},
				{"^=", NativeLanguagePunctuationID::CaretEqual},
				{"&=", NativeLanguagePunctuationID::AndEqual},
				{"|=", NativeLanguagePunctuationID::OrEqual},
				{"||", NativeLanguagePunctuationID::DoubleEqual},
				{"!=", NativeLanguagePunctuationID::ExclamationEqual},
				{"<", NativeLanguagePunctuationID::Less},
				{">", NativeLanguagePunctuationID::Greater},
				{"<=", NativeLanguagePunctuationID::LessEqual},
				{">=", NativeLanguagePunctuationID::GreaterEqual},
				{"<=>", NativeLanguagePunctuationID::LessEqualGreater},
				{"&&", NativeLanguagePunctuationID::DoubleAnd},
				{"||", NativeLanguagePunctuationID::DoubleOr},
				{"<<", NativeLanguagePunctuationID::DoubleLess},
				{">>", NativeLanguagePunctuationID::DoubleGreater},
				{"<<=", NativeLanguagePunctuationID::DoubleLessEqual},
				{">>=", NativeLanguagePunctuationID::DoubleGreaterEqual},
				{"++", NativeLanguagePunctuationID::DoublePlus},
				{"--", NativeLanguagePunctuationID::DoubleMinus},
				{",", NativeLanguagePunctuationID::Comma}
			},
			//Keywords
			{
				{"alignas" , NativeLanguageKeywordID::KeywordAlignas},
				{"alignof" , NativeLanguageKeywordID::KeywordAlignof},
				{"and" , NativeLanguageKeywordID::KeywordAnd},
				{"and_eq" , NativeLanguageKeywordID::KeywordAnd_eq},
				{"asm" , NativeLanguageKeywordID::KeywordAsm},
				{"atomic_cancel" , NativeLanguageKeywordID::KeywordAtomic_cancel},
				{"atomic_commit" , NativeLanguageKeywordID::KeywordAtomic_commit},
				{"atomic_noexcept" , NativeLanguageKeywordID::KeywordAtomic_noexcept},
				{"auto" , NativeLanguageKeywordID::KeywordAuto},
				{"bitand" , NativeLanguageKeywordID::KeywordBitand},
				{"bitor" , NativeLanguageKeywordID::KeywordBitor},
				{"bool" , NativeLanguageKeywordID::KeywordBool},
				{"break" , NativeLanguageKeywordID::KeywordBreak},
				{"case" , NativeLanguageKeywordID::KeywordCase},
				{"catch" , NativeLanguageKeywordID::KeywordCatch},
				{"char" , NativeLanguageKeywordID::KeywordChar},
				{"char8_t" , NativeLanguageKeywordID::KeywordChar8_t},
				{"char16_t" , NativeLanguageKeywordID::KeywordChar16_t},
				{"char32_t" , NativeLanguageKeywordID::KeywordChar32_t},
				{"class" , NativeLanguageKeywordID::KeywordClass},
				{"compl" , NativeLanguageKeywordID::KeywordCompl},
				{"concept" , NativeLanguageKeywordID::KeywordConcept},
				{"const" , NativeLanguageKeywordID::KeywordConst},
				{"consteval" , NativeLanguageKeywordID::KeywordConsteval},
				{"constexpr" , NativeLanguageKeywordID::KeywordConstexpr},
				{"constinit" , NativeLanguageKeywordID::KeywordConstinit},
				{"const_cast" , NativeLanguageKeywordID::KeywordConst_cast},
				{"continue" , NativeLanguageKeywordID::KeywordContinue},
				{"co_await" , NativeLanguageKeywordID::KeywordCo_await},
				{"co_return" , NativeLanguageKeywordID::KeywordCo_return},
				{"co_yield" , NativeLanguageKeywordID::KeywordCo_yield},
				{"decltype" , NativeLanguageKeywordID::KeywordDecltype},
				{"default" , NativeLanguageKeywordID::KeywordDefault},
				{"delete" , NativeLanguageKeywordID::KeywordDelete},
				{"do" , NativeLanguageKeywordID::KeywordDo},
				{"double" , NativeLanguageKeywordID::KeywordDouble},
				{"dynamic_cast" , NativeLanguageKeywordID::KeywordDynamic_cast},
				{"else" , NativeLanguageKeywordID::KeywordElse},
				{"enum" , NativeLanguageKeywordID::KeywordEnum},
				{"explicit" , NativeLanguageKeywordID::KeywordExplicit},
				{"export" , NativeLanguageKeywordID::KeywordExport},
				{"extern" , NativeLanguageKeywordID::KeywordExtern},
				{"false" , NativeLanguageKeywordID::KeywordFalse},
				{"float" , NativeLanguageKeywordID::KeywordFloat},
				{"for" , NativeLanguageKeywordID::KeywordFor},
				{"friend" , NativeLanguageKeywordID::KeywordFriend},
				{"goto" , NativeLanguageKeywordID::KeywordGoto},
				{"if" , NativeLanguageKeywordID::KeywordIf},
				{"inline" , NativeLanguageKeywordID::KeywordInline},
				{"int" , NativeLanguageKeywordID::KeywordInt},
				{"long" , NativeLanguageKeywordID::KeywordLong},
				{"mutable" , NativeLanguageKeywordID::KeywordMutable},
				{"namespace" , NativeLanguageKeywordID::KeywordNamespace},
				{"new" , NativeLanguageKeywordID::KeywordNew},
				{"noexcept" , NativeLanguageKeywordID::KeywordNoexcept},
				{"not" , NativeLanguageKeywordID::KeywordNot},
				{"not_eq" , NativeLanguageKeywordID::KeywordNot_eq},
				{"nullptr" , NativeLanguageKeywordID::KeywordNullptr},
				{"operator" , NativeLanguageKeywordID::KeywordOperator},
				{"or" , NativeLanguageKeywordID::KeywordOr},
				{"or_eq" , NativeLanguageKeywordID::KeywordOr_eq},
				{"private" , NativeLanguageKeywordID::KeywordPrivate},
				{"protected" , NativeLanguageKeywordID::KeywordProtected},
				{"public" , NativeLanguageKeywordID::KeywordPublic},
				{"reflexpr" , NativeLanguageKeywordID::KeywordReflexpr},
				{"register" , NativeLanguageKeywordID::KeywordRegister},
				{"reinterpret_cast" , NativeLanguageKeywordID::KeywordReinterpret_cast},
				{"requires" , NativeLanguageKeywordID::KeywordRequires},
				{"return" , NativeLanguageKeywordID::KeywordReturn},
				{"short" , NativeLanguageKeywordID::KeywordShort},
				{"signed" , NativeLanguageKeywordID::KeywordSigned},
				{"sizeof" , NativeLanguageKeywordID::KeywordSizeof},
				{"static" , NativeLanguageKeywordID::KeywordStatic},
				{"static_assert" , NativeLanguageKeywordID::KeywordStatic_assert},
				{"static_cast" , NativeLanguageKeywordID::KeywordStatic_cast},
				{"struct" , NativeLanguageKeywordID::KeywordStruct},
				{"switch" , NativeLanguageKeywordID::KeywordSwitch},
				{"synchronized" , NativeLanguageKeywordID::KeywordSynchronized},
				{"template" , NativeLanguageKeywordID::KeywordTemplate},
				{"this" , NativeLanguageKeywordID::KeywordThis},
				{"thread_local" , NativeLanguageKeywordID::KeywordThread_local},
				{"throw" , NativeLanguageKeywordID::KeywordThrow},
				{"true" , NativeLanguageKeywordID::KeywordTrue},
				{"try" , NativeLanguageKeywordID::KeywordTry},
				{"typedef" , NativeLanguageKeywordID::KeywordTypedef},
				{"typeid" , NativeLanguageKeywordID::KeywordTypeid},
				{"typename" , NativeLanguageKeywordID::KeywordTypename},
				{"union" , NativeLanguageKeywordID::KeywordUnion},
				{"unsigned" , NativeLanguageKeywordID::KeywordUnsigned},
				{"using" , NativeLanguageKeywordID::KeywordUsing},
				{"virtual" , NativeLanguageKeywordID::KeywordVirtual},
				{"void" , NativeLanguageKeywordID::KeywordVoid},
				{"volatile" , NativeLanguageKeywordID::KeywordVolatile},
				{"wchar_t" , NativeLanguageKeywordID::KeywordWchar_t},
				{"while" , NativeLanguageKeywordID::KeywordWhile},
				{"xor" , NativeLanguageKeywordID::KeywordXor},
				{"xor_eq" , NativeLanguageKeywordID::KeywordXor_eq}
			},
			//Numbers
			{
				NumberFormat(10, "", "", 0), //INT
				NumberFormat(10, "", "u", 0), //UINT
				NumberFormat(10, "", "l", 0), //LONG,
				NumberFormat(10, "", "ul", 0), //UNSIGNED LONG
				NumberFormat(10, "", "lu", 0), //UNSIGNED LONG
				NumberFormat(10, "", "ll", 0), //LONG LONG
				NumberFormat(10, "", "ull", 0), //UNSIGNED LONG LONG
				NumberFormat(10, "", "llu", 0), //UNSIGNED LONG LONG

				NumberFormat(10, "", "", '.'), //DOUBLE
				NumberFormat(10, "", "l", '.'), //LONG DOUBLE
				NumberFormat(10, "", "f", '.'), //FLOAT
				NumberFormat(16, "0x", "", 0), //HEX INT
				NumberFormat(16, "0x", "u", 0), //HEX UNSIGNED INT
				NumberFormat(16, "0x", "l", 0), //HEX LONG INT
				NumberFormat(16, "0x", "ll", 0), //HEX INT LONG LONG
				NumberFormat(16, "0x", "ull", 0), //HEX UNSIGNED LONG LONG
				NumberFormat(16, "0x", "llu", 0), //HEX UNSIGNED LONG LONG
				NumberFormat(2, "0b", "", 0), //BIANRY INT
				NumberFormat(2, "0b", "u", 0), //BIANRY UNSIGNED INT
				NumberFormat(2, "0b", "l", 0), //BIANRY LONG INT
				NumberFormat(2, "0b", "ll", 0), //BIANRY INT LONG LONG
				NumberFormat(2, "0b", "ull", 0), //BIANRY UNSIGNED LONG LONG
				NumberFormat(2, "0b", "llu", 0) //BIANRY UNSIGNED LONG LONG
			},
			'\"',
			'\\',
			'\''
		},
		//C#
		{ {}, {} }
	};

#pragma endregion
	Punctuation::Punctuation(const std::string& separator, uint32_t enum_value) : m_punctuation(separator), m_enum_value(enum_value) {}
	const std::string& Punctuation::Value() const { return m_punctuation; }
	uint32_t Punctuation::EnumValue() const { return m_enum_value; }
	Keyword::Keyword(const std::string word, uint32_t enum_value) : m_word(word), m_enum_value(enum_value) {}
	const std::string& Keyword::Value() const { return m_word; }
	uint32_t Keyword::EnumValue() const { return m_enum_value; }
	LexerDialect::LexerDialect(const DialectInfo& dialect)
	{
		m_keywords = dialect.keywords;
		m_separators = dialect.separators;
		m_number_formats = dialect.number_formats;
		m_string_char = dialect.string_char;
		m_string_escape_char = dialect.string_escape_char;
		m_number_separator = dialect.number_separator;
		std::sort(m_keywords.begin(), m_keywords.end(), cmp_keyword);
		std::sort(m_separators.begin(), m_separators.end(), cmp_separator);

		std::sort(m_number_formats.begin(), m_number_formats.end(), cmp_number_format);
	}
	LexerDialect::LexerDialect(NativeLanguageDialect nativeLanguage)
	{
		const auto& dialect = native_language_dialects[(int)nativeLanguage];
		m_keywords = dialect.keywords;
		m_separators = dialect.separators;
		m_number_formats = dialect.number_formats;
		m_string_char = dialect.string_char;
		m_string_escape_char = dialect.string_escape_char;
		m_number_separator = dialect.number_separator;
		std::sort(m_keywords.begin(), m_keywords.end(), cmp_keyword);
		std::sort(m_separators.begin(), m_separators.end(), cmp_separator);

		std::sort(m_number_formats.begin(), m_number_formats.end(), cmp_number_format);
	}
	const std::vector<Punctuation>& LexerDialect::Separators() const { return m_separators; }
	const std::vector<Keyword>& LexerDialect::Keywords() const { return m_keywords; }
	const std::vector<NumberFormat>& LexerDialect::Numbers() const { return m_number_formats; }
	char LexerDialect::StringChar() const { return m_string_char; }
	char LexerDialect::StringEscapeChar() const { return m_string_escape_char; }
	char LexerDialect::NumberSeparatorChar() const { return m_number_separator; }
	int8_t CharToInt(char c) 
	{
		if (c >= '0' && c <= '9')
			return c - '0';
		c = std::tolower(c);
		if (c >= 'a' && c <= 'z')
			return c - 'a' + 10;
		return -1;
	}
	char IntToChar(int8_t v) 
	{
		if (v < 10)
			return '0' + v;
		return 'a' + v - 10;
	}
	bool IsCharValidForBase(int8_t base, char c) 
	{
		c = std::tolower(c);
		if (c >= '0' && c <= '9')
			return (c - '0') < base;
		if(c >= 'a' && c <= 'z')
			return (c - 'a' + 10) < base;
		return false;
	}
	NumberFormat::NumberFormat(int8_t base, const std::string& prefix, const std::string& sufix, char point):
		m_base(base),
		m_prefix(prefix),
		m_sufix(sufix),
		m_point(point) {}
	bool NumberFormat::ParseToBinaryNumber(const std::string& value, double& out) const
	{
		size_t length = value.length();
		if (length < (m_prefix.length() + m_sufix.length()))
			return false;
		for (int8_t i = 0; i < m_prefix.length(); ++i)
			if (value[i] != m_prefix[i])
				return false;
		for (int8_t i = 0; i < m_sufix.length(); ++i)
			if (value[length - m_sufix.length() + i] != m_sufix[i])
				return false;
		std::string number = value.substr(m_prefix.length(), length - (m_prefix.length() + m_sufix.length()));
		out = 0;

		size_t point_pos = number.find(m_point);
		if (point_pos == std::string::npos)
			point_pos = number.length() - 1;
		else {
			number.erase(number.begin() + point_pos);
			--point_pos;
		}
		for (int8_t i = 0; i < number.length(); ++i) 
		{
			char c = number[i];
			int8_t value = CharToInt(c);
			if (value < 0)
				return false;
			int8_t loc = point_pos - i;
			double result = pow(m_base, loc);
			result *= value;
			out += result;
		}
		return true;
	}
	const std::string& NumberFormat::Prefix() const { return m_prefix; }
	const std::string& NumberFormat::Sufix() const { return m_sufix; }
	int8_t NumberFormat::Base() const { return m_base; }
	char NumberFormat::Point() const { return m_point; }
	bool TryMatch(uint32_t cursor, const std::string& source, const std::string& match) 
	{
		for (size_t i = 0; i < match.length(); ++i) 
		{
			uint32_t index = cursor + i;
			if (index >= source.length())
				return false;
			char c = source[index];
			if (c == '\n')
				return false;
			if (source[cursor + i] != match[i])
				return false;
		}
		return true;
	}

	Lexer::Lexer(const std::string& source, const LexerDialect& dialect):
		m_dialect(dialect),
		m_source(source) {
		Process();
	}

	Lexer::Lexer(const std::string& source, NativeLanguageDialect dialect):
		m_source(source),
		m_dialect(native_language_dialects[(int)dialect]) {
		Process();
	}

	const std::vector<Token>& Lexer::Tokens() const
	{
		return m_tokens;
	}

	void Lexer::Process()
	{
		Location location{};
		int32_t cursor = -1;
		Token output{};
		while (cursor++ < (int32_t)m_source.length())
		{
			char chr = m_source[cursor];
			if (chr == '\0')
				continue;
			if (chr == '\n')
			{
				location.Line++;
				location.Collumn = 0;
				continue;
			}
			if (chr == '\t') 
			{
				location.Collumn += 4;
				continue;
			}

			if (std::isspace(chr))
			{
				++location.Collumn;
				continue;
			}

			//Check if punctuation
			bool is_punctuation = false;
			for (auto& punct : m_dialect.Separators())
			{
				auto& value = punct.Value();
				if (!TryMatch(cursor, m_source, value))
					continue;
				is_punctuation = true;
				output.location = location;
				output.punctuation_id = punct.EnumValue();
				output.type = TokenType::Punctuation;
				output.value = value;
				m_tokens.push_back(output);
				output = Token{};
				location.Collumn += value.length();
				cursor += value.length() - 1;
				break;
			}
			if (is_punctuation)
				continue;
			//Check if keyword
			bool is_keyword = false;
			for (auto& keyword : m_dialect.Keywords()) 
			{
				auto& value = keyword.Value();
				if (!(TryMatch(cursor, m_source, value) && std::isspace(m_source[cursor+value.length()])))
					continue;
				is_keyword = true;
				output.location = location;
				output.punctuation_id = keyword.EnumValue();
				output.type = TokenType::Keyword;
				output.value = value;
				m_tokens.push_back(output);
				output = Token{};
				location.Collumn += value.length();
				cursor += value.length() - 1;
				break;
			}
			if (is_keyword)
				continue;

			std::string word;
			Location loc = location;
			//Check if number
			
			bool is_number = false;
			auto old_cursor = cursor;
			Location old_location = location;
			for (auto& number : m_dialect.Numbers()) 
			{
				cursor = old_cursor;
				location = old_location;
				auto& prefix = number.Prefix();
				std::string nr;
				if (!TryMatch(cursor, m_source, prefix))
					continue;
				nr += prefix;
				cursor += prefix.length();
				location.Collumn += prefix.length();
				bool number_valid = true;
				bool m_point_found = false;
				while (cursor < m_source.length()) 
				{
					char c = m_source[cursor];
					if (IsCharValidForBase(number.Base(), c)) 
					{
						nr += c;
						++cursor;
						location.Collumn++;
						continue;
					}
					if (!m_point_found && c == number.Point())
					{
						m_point_found = true;
						nr += c;
						++cursor;
						location.Collumn++;
						continue;
					}
					if (c == m_dialect.NumberSeparatorChar())
					{
						cursor++;
						location.Collumn++;
						continue;
					}
					//This means that the number has finished, need to chjeck for sufix
					if (nr.length() == prefix.length()) 
					{
						number_valid = false;
						break;
					}
					if (!TryMatch(cursor, m_source, number.Sufix())) 
					{
						number_valid = false;
						break;
					}
					nr += number.Sufix();
					cursor += number.Sufix().length();
					location.Collumn += number.Sufix().length();
					number_valid = true;
					--cursor;
					break;
				}
				if (!number_valid)
					continue;
				output.location = old_location;
				output.type = TokenType::Value;
				output.value_type = ValueType::Number;
				output.number_format = number;
				output.value = nr;
				m_tokens.push_back(output);
				output = Token{};
				is_number = true;
				break;
			}
			if (is_number)
				continue;



			//Check if string
			if (chr == m_dialect.StringChar()) 
			{
				bool escape = false;
				bool string_started = false;
				while (cursor < m_source.length()) 
				{
					char c = m_source[cursor];
					if (c == m_dialect.StringChar()) 
					{
						if (!string_started) 
						{
							string_started = true;
							word += c;
							cursor++;
							location.Collumn++;
							continue;
						}
						else if(!escape)
						{
							location.Collumn++;
							word += c;
							output.location = loc;
							output.type = TokenType::Value;
							output.value_type = ValueType::String;
							output.value = word;
							m_tokens.push_back(output);
							output = Token{};
							break;
						}
						else 
						{
							word += c;
							cursor++;
							location.Collumn++;
							escape = false;
							continue;
						}
					}
					if (c == m_dialect.StringEscapeChar()) {
						escape = true;
						cursor++;
						location.Collumn++;
						continue;
					}
					word += c;
					cursor++;
					location.Collumn++;
				}
				continue;
			}


			//Read word
			while (cursor < m_source.length()) 
			{
				bool p = false;
				for (auto& punct : m_dialect.Separators())
				{
					auto& value = punct.Value();
					if (!TryMatch(cursor, m_source, value))
						continue;
					p = true;
				}
				char c = m_source[cursor];
				if (std::isspace(c) || c == '\n' || p) {
					cursor--;
					output.location = loc;
					output.value = word;
					output.type = TokenType::Value;
					output.value_type = ValueType::Word;
					m_tokens.push_back(output);
					output = Token{};
					break;
				}
				word += m_source[cursor];
				cursor++;
				location.Collumn++;
			}
		}
	}

	Parser::Parser(const std::vector<Token>& tokens) : m_tokens(tokens) {}
	Parser::Parser(const Lexer& lexer) : m_tokens(lexer.Tokens()) {}

	bool Parser::Next(Token& out)
	{
		if (m_cursor >= m_tokens.size())
			return false;
		out = m_tokens[m_cursor++];
		return true;
	}

	bool Parser::Back(Token& out)
	{
		if (m_cursor >= m_tokens.size())
			return false;
		out = m_tokens[m_cursor--];
		return true;
	}

	void Parser::Skip(size_t count)
	{
		m_cursor += count;
	}

	bool Parser::Skip(Token& out, size_t count)
	{
		m_cursor += count;
		return Next(out);
	}

	bool Parser::Valid()
	{
		return m_cursor < m_tokens.size();
	}

	bool Parser::TryMatch(const std::vector<TokenMatchTemplate>& match, size_t target_match)
	{
		if (m_cursor + match.size() > m_tokens.size())
			return false;
		for (size_t i = 0; i < match.size(); ++i) 
		{
			auto& token = m_tokens[m_cursor + i];
			auto& m = match[i];
			if (token.type != m.type)
				return false;
			if (token.value_type != m.value_type)
				return false;
			if (m.type == TokenType::Value && m.value.length() != 0) 
			{
				if (m.value != token.value)
					return false;
			}
			bool v = true;
			switch (token.type)
			{
			case TokenType::Punctuation:
				if (m.punctuation != 0)
					v = (m.punctuation == token.punctuation_id);
				break;
			case TokenType::Keyword:
				if (m.keyword != 0)
					v = (m.keyword == token.keyword_id);
				break;
			}
			if (!v)
				return false;
		}
		m_cursor += target_match;
		return true;
	}

	TokenMatchTemplate TokenMatchTemplate::MatchValue(ValueType type, std::string value)
	{
		TokenMatchTemplate t;
		t.type = TokenType::Value;
		t.value_type = type;
		t.value = value;
		return t;
	}

	TokenMatchTemplate TokenMatchTemplate::MatchPunctuation(uint32_t punctuation)
	{
		TokenMatchTemplate t;
		t.type = TokenType::Punctuation;
		t.punctuation = punctuation;
		return t;
	}

	TokenMatchTemplate TokenMatchTemplate::MatchKeyword(uint32_t keyword)
	{
		TokenMatchTemplate t;
		t.type = TokenType::Keyword;
		t.keyword = keyword;
		return t;
	}

}