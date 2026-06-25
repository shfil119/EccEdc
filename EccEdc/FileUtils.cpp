#include "FileUtils.hpp"

namespace FileUtils {
	bool readFileLines(const char* filePath, std::vector<std::string> & lines) {
		std::ifstream infile(filePath);
		if (!infile.is_open())
			return FALSE;

		std::string line;

		while (std::getline(infile, line)) {
			lines.push_back(line);
		}

		return true;
	}

	bool getFileSize(const char* filePath, uint32_t & fileSize) {
		bool retVal = FALSE;

		HANDLE fileHandle = CreateFile(filePath, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
		if (fileHandle != INVALID_HANDLE_VALUE) {
			retVal = (fileSize = GetFileSize(fileHandle, NULL)) != INVALID_FILE_SIZE;

			CloseHandle(fileHandle);
		}

		return retVal;
	}
}
