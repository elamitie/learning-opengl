#pragma once

#include <vector>

namespace lamengine {

	class IOManager
	{
	public:
		static bool readFileToBuffer(std::string filepath, std::vector<unsigned char>& buffer);
		static bool readFileToBuffer(std::string filepath, std::string& buffer);
	};

}