#include <iostream>
#include <fstream>
#include <sstream>

int	error(std::string status)
{
	std::cout << "Error : " << status << std::endl;
	return (1);
}

int	main(int argc, char** argv)
{
	if (argc != 4)
		return (error("Too many/few arguments"));
	if (!argv[2] || !argv[3])
		return (error("Empty strings provided as arguments"));
	
	std::ifstream		file(argv[1]);
	std::string			filename;
	std::string			content;
	std::string			s1;
	std::string			s2;
	std::stringstream	buff;
	size_t				pos;

	if( file.is_open())
	{
		pos = 0;
		s1 = argv[2];
		s2 = argv[3];
		filename = argv[1];
		filename.append(".replace");

		std::ofstream		output(filename);
		
		buff << file.rdbuf();
		content = buff.str();
		while((pos = content.find(s1, pos)) != std::string::npos)
		{
			content.erase(pos, s1.length());
			content.insert(pos, s2);
			pos += s2.length();
		}
		output << content;
	}
	else
		return(error("File does not exist in this directory"));	
	return (0);
}