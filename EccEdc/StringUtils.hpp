#ifndef _STRING_UTILS_HPP_
#define _STRING_UTILS_HPP_

#include <string>

namespace StringUtils {
	bool startsWith(const std::wstring & str, const std::wstring & lookFor);
	bool startsWith(const std::string & str, const std::string & lookFor);
	bool endsWith(const std::wstring & str, const std::wstring & lookFor);
	bool endsWith(const std::string & str, const std::string & lookFor);
	bool equals(const std::wstring & str, const std::wstring & other);
	bool equals(const std::string & str, const std::string & other);
	bool contains(const std::wstring & str, const std::wstring & lookFor);
	bool contains(const std::string & str, const std::string & lookFor);

	std::string getDirectoryFromPath(const std::string & filePath);

	void trim(std::wstring & line);
	void trim(std::string & line);

	void trimBegin(std::wstring & line);
	void trimBegin(std::string & line);

	void trimEnd(std::wstring & line);
	void trimEnd(std::string & line);
};

#endif
