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

void BitMapClass::getPicturePlane(std::istream &in){
	auto *plane_line = new std::vector<RGBQuads*>(i_header->bmiWidth);
	plane = new Plane(i_header->bmiHeight, *plane_line);
	in.seekg(f_header->bmfOffBits, in.beg);
	switch (i_header->bmiBitCount){
	case 8:
		for (int i = 0; i < i_header->bmiHeight; i++){
			for (int j = 0; j < i_header->bmiWidth; j++){
				char num_palette;
				in >> num_palette;
				plane->at(i).at(j) = palette->at(num_palette);
			}
		}
		break;
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