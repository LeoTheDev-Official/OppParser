#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <functional>
#define OPP_PARSER_NAMESPACE Opportunity

namespace OPP_PARSER_NAMESPACE 
{
#define P_COUNTER (uint32_t)(~0 - (__LINE__ - 12))
	enum NativeLanguagePunctuationID : uint32_t
	{
		OpenCurly			= P_COUNTER,
		ClosedCurly			= P_COUNTER,
		OpenSquare			= P_COUNTER,
		ClosedSquare		= P_COUNTER,
		Hash				= P_COUNTER,
		DoubleHash			= P_COUNTER,
		OpenParen			= P_COUNTER,
		ClosedParen			= P_COUNTER,
		SemiColon			= P_COUNTER,
		Colon				= P_COUNTER,
		Expand				= P_COUNTER,
		QuestionMark		= P_COUNTER,
		DoubleColon			= P_COUNTER,
		Dot					= P_COUNTER,
		DotStar				= P_COUNTER,
		RightArrow			= P_COUNTER,
		RightArrowStar		= P_COUNTER,
		Grave				= P_COUNTER,
		Exclamation			= P_COUNTER,
		Plus				= P_COUNTER,
		Minus				= P_COUNTER,
		Star				= P_COUNTER,
		Slash				= P_COUNTER,
		Percent				= P_COUNTER,
		Caret				= P_COUNTER,
		And					= P_COUNTER,
		Or					= P_COUNTER,
		Equal				= P_COUNTER,
		PlusEqual			= P_COUNTER,
		MinusEqual			= P_COUNTER,
		StarEqual			= P_COUNTER,
		SlashEqual			= P_COUNTER,
		PercentEqual		= P_COUNTER,
		CaretEqual			= P_COUNTER,
		AndEqual			= P_COUNTER,
		OrEqual				= P_COUNTER,
		DoubleEqual			= P_COUNTER,
		ExclamationEqual	= P_COUNTER,
		Less				= P_COUNTER,
		Greater				= P_COUNTER,
		LessEqual			= P_COUNTER,
		GreaterEqual		= P_COUNTER,
		LessEqualGreater	= P_COUNTER,
		DoubleAnd			= P_COUNTER,
		DoubleOr			= P_COUNTER,
		DoubleLess			= P_COUNTER,
		DoubleGreater		= P_COUNTER,
		DoubleLessEqual		= P_COUNTER,
		DoubleGreaterEqual	= P_COUNTER,
		DoublePlus			= P_COUNTER,
		DoubleMinus			= P_COUNTER,
		Comma				= P_COUNTER
	};
#define K_COUNTER (uint32_t)(~0 - (__LINE__ - 68))
	enum NativeLanguageKeywordID : uint32_t
	{
		KeywordAlignas				= K_COUNTER,
		KeywordAlignof				= K_COUNTER,
		KeywordAnd					= K_COUNTER,
		KeywordAnd_eq				= K_COUNTER,
		KeywordAsm					= K_COUNTER,
		KeywordAtomic_cancel		= K_COUNTER,
		KeywordAtomic_commit		= K_COUNTER,
		KeywordAtomic_noexcept		= K_COUNTER,
		KeywordAuto					= K_COUNTER,
		KeywordBitand				= K_COUNTER,
		KeywordBitor				= K_COUNTER,
		KeywordBool					= K_COUNTER,
		KeywordBreak				= K_COUNTER,
		KeywordCase					= K_COUNTER,
		KeywordCatch				= K_COUNTER,
		KeywordChar					= K_COUNTER,
		KeywordChar8_t				= K_COUNTER,
		KeywordChar16_t				= K_COUNTER,
		KeywordChar32_t				= K_COUNTER,
		KeywordClass				= K_COUNTER,
		KeywordCompl				= K_COUNTER,
		KeywordConcept				= K_COUNTER,
		KeywordConst				= K_COUNTER,
		KeywordConsteval			= K_COUNTER,
		KeywordConstexpr			= K_COUNTER,
		KeywordConstinit			= K_COUNTER,
		KeywordConst_cast			= K_COUNTER,
		KeywordContinue				= K_COUNTER,
		KeywordCo_await				= K_COUNTER,
		KeywordCo_return			= K_COUNTER,
		KeywordCo_yield				= K_COUNTER,
		KeywordDecltype				= K_COUNTER,
		KeywordDefault				= K_COUNTER,
		KeywordDelete				= K_COUNTER,
		KeywordDo					= K_COUNTER,
		KeywordDouble				= K_COUNTER,
		KeywordDynamic_cast			= K_COUNTER,
		KeywordElse					= K_COUNTER,
		KeywordEnum					= K_COUNTER,
		KeywordExplicit				= K_COUNTER,
		KeywordExport				= K_COUNTER,
		KeywordExtern				= K_COUNTER,
		KeywordFalse				= K_COUNTER,
		KeywordFloat				= K_COUNTER,
		KeywordFor					= K_COUNTER,
		KeywordFriend				= K_COUNTER,
		KeywordGoto					= K_COUNTER,
		KeywordIf					= K_COUNTER,
		KeywordInline				= K_COUNTER,
		KeywordInt					= K_COUNTER,
		KeywordLong					= K_COUNTER,
		KeywordMutable				= K_COUNTER,
		KeywordNamespace			= K_COUNTER,
		KeywordNew					= K_COUNTER,
		KeywordNoexcept				= K_COUNTER,
		KeywordNot					= K_COUNTER,
		KeywordNot_eq				= K_COUNTER,
		KeywordNullptr				= K_COUNTER,
		KeywordOperator				= K_COUNTER,
		KeywordOr					= K_COUNTER,
		KeywordOr_eq				= K_COUNTER,
		KeywordPrivate				= K_COUNTER,
		KeywordProtected			= K_COUNTER,
		KeywordPublic				= K_COUNTER,
		KeywordReflexpr				= K_COUNTER,
		KeywordRegister				= K_COUNTER,
		KeywordReinterpret_cast		= K_COUNTER,
		KeywordRequires				= K_COUNTER,
		KeywordReturn				= K_COUNTER,
		KeywordShort				= K_COUNTER,
		KeywordSigned				= K_COUNTER,
		KeywordSizeof				= K_COUNTER,
		KeywordStatic				= K_COUNTER,
		KeywordStatic_assert		= K_COUNTER,
		KeywordStatic_cast			= K_COUNTER,
		KeywordStruct				= K_COUNTER,
		KeywordSwitch				= K_COUNTER,
		KeywordSynchronized			= K_COUNTER,
		KeywordTemplate				= K_COUNTER,
		KeywordThis					= K_COUNTER,
		KeywordThread_local			= K_COUNTER,
		KeywordThrow				= K_COUNTER,
		KeywordTrue					= K_COUNTER,
		KeywordTry					= K_COUNTER,
		KeywordTypedef				= K_COUNTER,
		KeywordTypeid				= K_COUNTER,
		KeywordTypename				= K_COUNTER,
		KeywordUnion				= K_COUNTER,
		KeywordUnsigned				= K_COUNTER,
		KeywordUsing				= K_COUNTER,
		KeywordVirtual				= K_COUNTER,
		KeywordVoid					= K_COUNTER,
		KeywordVolatile				= K_COUNTER,
		KeywordWchar_t				= K_COUNTER,
		KeywordWhile				= K_COUNTER,
		KeywordXor					= K_COUNTER,
		KeywordXor_eq				= K_COUNTER
	};
	enum class NativeLanguageDialect 
	{
		C,
		Cpp,
		CSharp
	};
	class Punctuation 
	{
	public:
		Punctuation(const std::string& punctuation, uint32_t enum_value);
		const std::string& Value() const;
		uint32_t EnumValue() const;
	private:
		std::string m_punctuation;
		int m_enum_value;
	};
	class Keyword 
	{
	public:
		Keyword(const std::string word, uint32_t enum_value);
		const std::string& Value() const;
		uint32_t EnumValue() const;
	private:
		std::string m_word;
		int m_enum_value;
	};
	class NumberFormat 
	{
	public:
		NumberFormat() {};
		NumberFormat(int8_t base, const std::string& prefix, const std::string& sufix, char point = 0);
		bool ParseToBinaryNumber(const std::string& value, double& out) const;
		const std::string& Prefix() const;
		const std::string& Sufix() const;
		int8_t Base() const;
		char Point() const;
	private:
		int8_t m_base;
		std::string m_prefix;
		std::string m_sufix;
		char m_point;
	};
	
	struct DialectInfo 
	{
		std::vector<Punctuation> separators;
		std::vector<Keyword> keywords;
		std::vector<NumberFormat> number_formats;
		char string_char = '\"';
		char string_escape_char = '\\';
		char number_separator = '\'';
	};
	class LexerDialect 
	{
	public:
		LexerDialect(const DialectInfo& dialectInfo);
		LexerDialect(NativeLanguageDialect nativeLanguage);
		const std::vector<Punctuation>& Separators() const;
		const std::vector<Keyword>& Keywords() const;
		const std::vector<NumberFormat>& Numbers() const;
		char StringChar() const;
		char StringEscapeChar() const;
		char NumberSeparatorChar() const;
	private:
		std::vector<Punctuation> m_separators;
		std::vector<Keyword> m_keywords;
		std::vector<NumberFormat> m_number_formats;
		char m_string_char;
		char m_string_escape_char;
		char m_number_separator;
	};

	enum class TokenType 
	{
		Punctuation,
		Keyword,
		Value
	};
	enum class ValueType 
	{
		Word,
		String,
		Number
	};
	struct Location 
	{
		uint32_t Line;
		uint32_t Collumn;
	};
	struct Token 
	{
		Location location{};
		TokenType type = TokenType::Value;
		ValueType value_type = ValueType::Word;
		uint32_t keyword_id;
		uint32_t punctuation_id;
		std::string value;
		NumberFormat number_format{};
	};

	class Lexer 
	{
	public:
		Lexer() = delete;
		Lexer(const std::string& source, const LexerDialect& dialect);
		Lexer(const std::string& source, NativeLanguageDialect dialect);
		
		const std::vector<Token>& Tokens() const;
	private:
		void Process();

	private:
		std::vector<Token> m_tokens;
		LexerDialect m_dialect;
		std::string m_source;

		Location m_cursor{};
	};

	struct TokenMatchTemplate 
	{
		static TokenMatchTemplate MatchValue(ValueType type, std::string value);
		static TokenMatchTemplate MatchPunctuation(uint32_t punctuation);
		static TokenMatchTemplate MatchKeyword(uint32_t keyword);
		TokenType type = {};
		ValueType value_type = {};
		uint32_t punctuation = {};
		uint32_t keyword = {};
		std::string value = "";
	};
	class Parser 
	{
	public:
		Parser() = delete;
		Parser(const std::vector<Token>& tokens);
		Parser(const Lexer& lexer);

		bool Next(Token& out);
		bool Back(Token& out);
		void Skip(size_t count = 1);
		bool Skip(Token& out, size_t count = 1);

		bool TryMatch(const std::vector<TokenMatchTemplate>& match);
	private:
		std::vector<Token> m_tokens;
		size_t m_cursor = 0;
	};
}