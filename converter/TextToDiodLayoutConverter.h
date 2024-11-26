#pragma once
#include"Header_converter.h"

#define SIZE_CHAR_Y 9
#define SIZE_CHAR_X 8
class TextToDiodLayoutConverter
{
private:
	sf::Vector2f size_matrix;
	sf::Vector2f size_char;
	sf::Vector2f offsets = {0,0};

	std::vector<std::vector<bool>> matrix;
    std::unordered_map<char, std::bitset<56>> map_char;
    
	bool initializedCharacterMapFlag = 1;
    
	void initializeCharacterMap() {
		map_char.insert({ '0', std::bitset<56>(0b01111100100000101000001001111100) });
		map_char.insert({ '1', std::bitset<56>(0b00000000010000001111111000000000) });
		map_char.insert({ '2', std::bitset<56>(0b01000010100001101001101001100010) });
		map_char.insert({ '3', std::bitset<56>(0b01000100100000101001001001101100) });
		map_char.insert({ '4', std::bitset<56>(0b00011000001010000100100011111110) });
		map_char.insert({ '5', std::bitset<56>(0b11100100101000101010001010011100) });
		map_char.insert({ '6', std::bitset<56>(0b01111100100100101001001001011100) });
		map_char.insert({ '7', std::bitset<56>(0b10000000100011101011000011000000) });
		map_char.insert({ '8', std::bitset<56>(0b01101100100100101001001001101100) });
		map_char.insert({ '9', std::bitset<56>(0b01110100100100101001001001111100) });   
	}
	void InitializingMatrix( const size_t size_str) {
	
        size_matrix.x = SIZE_CHAR_X;
        size_matrix.y = SIZE_CHAR_Y;
        size_char.x = SIZE_CHAR_X;
        size_char.y = SIZE_CHAR_Y;

		size_matrix.x *= size_str;
		size_matrix.y *= size_str;

        offsets.x = 0;
        offsets.y = 0;
        matrix.clear();

		matrix.resize(size_matrix.y);
		for (auto& row : matrix) {
			row.resize(size_matrix.x);
		}

		if (initializedCharacterMapFlag) {
			initializeCharacterMap();
			initializedCharacterMapFlag = 0;
		}
	}
	
public:
	std::vector<std::vector<bool>> textToDiodMatrix(const std::string &input_str) {
	
		InitializingMatrix(input_str.size());

		for (int i = 0; i < input_str.size(); i++)
		{
		
             input_str[i];
			auto find_char = map_char.find(input_str[i]);
			int l = 0, j = 0, test = 0;;
			
			if (find_char != map_char.end()) {
			
				for (int i = 32; i >= 0; i--)
				{
					if(i<=31) matrix[offsets.y + j][offsets.x + l] = find_char->second[i];
					
					
					if (j % 8 == 0 and j!=0) {
						l++;
						j = 0;
						
					}
					if (l >= size_char.x) {
						l = 0;
						j = 0;
						test++;
					}
					j++;
					
				}
				offsets.x += size_char.x;
				
			}
           
			if (input_str[i] == '\n') {
				offsets.y += size_char.y;
				offsets.x = 0;
			}
		}
		return matrix;
	}

};

