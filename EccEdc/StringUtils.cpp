#include "StringUtils.hpp"

namespace StringUtils {
	bool startsWith(const std::wstring & str, const std::wstring & lookFor) {
		if (lookFor.size() > str.size())
			return false;

		return !StrCmpNIW(str.c_str(), lookFor.c_str(), (int)lookFor.size());
	}

	bool startsWith(const std::string & str, const std::string & lookFor) {
		if (lookFor.size() > str.size())
			return false;

		return !StrCmpNI(str.c_str(), lookFor.c_str(), (int)lookFor.size());
	}

	bool endsWith(const std::wstring & str, const std::wstring & lookFor) {
		if (lookFor.size() > str.size())
			return false;

		size_t offset = str.size() - lookFor.size();

		return !StrCmpNIW(str.c_str() + offset, lookFor.c_str(), (int)lookFor.size());
	}

	bool endsWith(const std::string & str, const std::string & lookFor) {
		if (lookFor.size() > str.size())
			return false;

		size_t offset = str.size() - lookFor.size();

		return !StrCmpNI(str.c_str() + offset, lookFor.c_str(), (int)lookFor.size());
	}

	bool equals(const std::wstring & str, const std::wstring & other) {
		if (str.size() != other.size())
			return false;

		return !_wcsicmp(str.c_str(), other.c_str());
	}

	bool equals(const std::string & str, const std::string & other) {
		if (str.size() != other.size())
			return false;

		return !_stricmp(str.c_str(), other.c_str());
	}

	bool contains(const std::wstring & str, const std::wstring & lookFor) {
		if (lookFor.size() > str.size())
			return false;

		return StrStrIW(str.c_str(), lookFor.c_str()) != NULL;
	}

	bool contains(const std::string & str, const std::string & lookFor) {
		if (lookFor.size() > str.size())
			return false;

		return StrStrI(str.c_str(), lookFor.c_str()) != NULL;
	}

	void trimEnd(std::wstring & line) {
		size_t charsSpace = 0;

		for (std::wstring::reverse_iterator iter = line.rbegin(); iter != line.rend(); ++iter) {
			if (*iter == L' ') {
				++charsSpace;
			}
			else {
				break;
			}
		}

		line.resize(line.size() - charsSpace);
	}

	void trimEnd(std::string & line) {
		size_t charsSpace = 0;

		for (std::string::reverse_iterator iter = line.rbegin(); iter != line.rend(); ++iter) {
			if (*iter == ' ') {
				++charsSpace;
			}
			else {
				break;
			}
		}

		line.resize(line.size() - charsSpace);
	}

	void trimBegin(std::wstring & line) {
		size_t charsSpace = 0;

		for (std::wstring::iterator iter = line.begin(); iter != line.end(); ++iter) {
			if (*iter == ' ') {
				++charsSpace;
			}
			else {
				break;
			}
		}

		line = line.substr(charsSpace);
	}

	void trimBegin(std::string & line) {
		size_t charsSpace = 0;

		for (std::string::iterator iter = line.begin(); iter != line.end(); ++iter) {
			if (*iter == ' ') {
				++charsSpace;
			}
			else {
				break;
			}
		}

		line = line.substr(charsSpace);
	}

	void trim(std::wstring & line) {
		trimBegin(line);
		trimEnd(line);
	}

	void trim(std::string & line) {
		trimBegin(line);
		trimEnd(line);
	}

	std::string getDirectoryFromPath(const std::string & filePath) {
		std::string path;

		size_t pos = filePath.find_last_of("\\/");
		if (pos != std::string::npos) {
			path = filePath.substr(0, pos + 1);
		}

		return path;
	}
}
