#include "BitMapClass.h"


//BIT_MAP_CLASS

BitMapClass::BitMapClass(std::istream &in)
{


	f_header = new BMapFileHeader();
	i_header = new BMapInfoHeader();
	palette = new BMapPalette();
	f_header->getBMFHeader(in);
	i_header->getBMIHeader(in);
	this->getBMapPallette(in);
	this->getPicturePlane(in);

}

BitMapClass::BitMapClass(QString f_name){
	std::ifstream fil;
	fil.open(f_name.toStdString(), std::ios::binary);
	while (!fil.eof()){
		char hlp;
		fil >> hlp;
		file_array.append(hlp);
	}
	
}

void BitMapClass::getPicturePlane(std::istream &in){
	auto *plane_line = new std::vector<RGBQuads*>(i_header->bmiWidth);
	plane = new Plane(i_header->bmiHeight, *plane_line);
//	plane.resize(i_header->bmiHeight*i_header->bmiWidth * 4);
	in.seekg(f_header->bmfOffBits, in.beg);
	x_size = i_header->bmiWidth;
	y_size = i_header->bmiHeight;
	

	for (int i = 0; i < i_header->bmiHeight; i++){

		int add = 0;
		switch (i_header->bmiBitCount){

		case 1:
			for (int j = 0; j < i_header->bmiWidth; j += 8){
				unsigned char num_palette;
				in.read((char*)&num_palette, 1);
				plane->at(i).at(j) = palette->at((num_palette >> 7) & 0x1);
				plane->at(i).at(j + 1) = palette->at((num_palette >> 6) & 0x1);
				plane->at(i).at(j + 2) = palette->at((num_palette >> 5) & 0x1);
				plane->at(i).at(j + 3) = palette->at((num_palette >> 4) & 0x1);
				plane->at(i).at(j + 4) = palette->at((num_palette >> 3) & 0x1);
				plane->at(i).at(j + 5) = palette->at((num_palette >> 2) & 0x1);
				plane->at(i).at(j + 6) = palette->at((num_palette >> 1) & 0x1);
				plane->at(i).at(j + 7) = palette->at((num_palette >> 0) & 0x1);
				add = (i_header->bmiWidth) % 4;
			}

			break;
		case 4:


			for (int j = 0; j < i_header->bmiWidth; j += 2){
				unsigned char num_palette;
				in.read((char*)&num_palette, 1);
				plane->at(i).at(j) = palette->at((num_palette >> 4) & 0xF);
				plane->at(i).at(j + 1) = palette->at((num_palette >> 0) & 0xF);
			}
			add = (i_header->bmiWidth) % 4;
			break;
		case 8:



			for (int j = 0; j < i_header->bmiWidth; j++){
				unsigned char num_palette;
				in.read((char*)&num_palette, 1);
				plane->at(i).at(j) = palette->at(num_palette);


			}
			add = (i_header->bmiWidth) % 4;
			break;
		case 24:

			for (int j = 0; j < i_header->bmiWidth; j++){
				RGBQuads *quads = new RGBQuads();
				in.read(&quads->B, 3);
				plane->at(i).at(j) = quads;

			}
			add = (i_header->bmiWidth*3) % 4;
			break;
		}
		
		if (add){
			int hlp;
			in.read((char*)hlp, add);
		}
		
	}
}

void BitMapClass::getBMapPallette(std::istream &in){
	unsigned int cur_adr;
	cur_adr = 14 + i_header->bmiSize;
	in.seekg(cur_adr, in.beg); //установили на начало палитры
	while (cur_adr < f_header->bmfOffBits){
		RGBQuads *new_rgb = new RGBQuads();
		new_rgb->getRGB(in);
		palette->push_back(new_rgb);
		cur_adr += 4;
	}

}


BitMapClass::~BitMapClass()
{
}

//BMapFileHeader
void BMapFileHeader::getBMFHeader(std::istream & in){
	unsigned char hlp;
	in.seekg(0, in.beg);
	in.read((char*)&bmfType, 2);
	in.read((char*)&bmfSize, 4);
	in.seekg(4, in.cur);
	in.read((char*)&bmfOffBits, 4);

}


//BMapInfoHeader

void BMapInfoHeader::getBMIHeader(std::istream & in){
	in.seekg(14, in.beg);
	unsigned char hlp;
	in.read((char*)&bmiSize, 4);
	in.read((char*)&bmiWidth, 4);
	in.read((char*)&bmiHeight, 4);
	in.read((char*)&bmiPlanes, 2);
	in.read((char*)&bmiBitCount, 2);
	in.read((char*)&bmiCompression, 4);
	in.read((char*)&bmiSizeImage, 4);
	in.read((char*)&bmiXPelsPerMeter, 4);
	in.read((char*)&bmiYPelsPerMeter, 4);
	in.read((char*)&bmiClrUsed, 4);
	in.read((char*)&bmiClrImportant, 4);
}

//RGBQuads

void RGBQuads::getRGB(std::istream &in){
	in.read((char*)&B, 4);
}