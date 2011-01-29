#ifndef _GLENUMS_H
#define _GLENUMS_H

#include <GL/glew.h>
#include <GL/gl.h>

#include <string>
#include <cassert>

#include <tr1/unordered_map>

class GLEnums
{
	public:
		GLEnums()
		{
			#define X(x) {enumToStr[x]=#x;strToEnum[#x]=x;}
			#include "glenums.def"
			#undef X
		}
		
		GLenum getEnum(const std::string & value) const
		{
			std::tr1::unordered_map <std::string, GLenum>::const_iterator i = strToEnum.find(value);
			if (i == strToEnum.end())
			{
				std::cerr << "Unknown GLenum string: " << value << std::endl;
				assert(0);
			}
			return i->second;
		}

		const std::string & getEnum(GLenum value) const
		{
			std::tr1::unordered_map <GLenum, std::string>::const_iterator i = enumToStr.find(value);
			if (i == enumToStr.end())
			{
				std::cerr << "Unknown GLenum value: " << (int)value << std::endl;
				assert(0);
			}
			return i->second;
		}
	
	private:
		std::tr1::unordered_map <std::string, GLenum> strToEnum;
		std::tr1::unordered_map <GLenum, std::string> enumToStr;
};

#undef ADD_GL_ENUM

#endif