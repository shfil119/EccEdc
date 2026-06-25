#ifndef _FILE_UTILS_HPP_
#define _FILE_UTILS_HPP_

#include <cstdint>
#include <vector>
#include <string>

namespace FileUtils {
	bool readFileLines(const char* filePath, std::vector<std::string> & lines);
	bool getFileSize(const char* filePath, uint32_t & fileSize);
};

#endif
