#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <QByteArray>
#include <QString>


enum { BI_RGB = 0, BI_RLE8, BI_RLE4, BI_BITFIELDS, BI_JPEG, BI_PNG, BI_ALPHABITFIELDS };




typedef struct _RGB_QUADS{
	char B;
	char G;
	char R;
	char F;

	void getRGB(std::istream &in);
} RGBQuads;

typedef std::vector<std::vector<RGBQuads*>> Plane;
//typedef QByteArray 

typedef std::vector<RGBQuads*> BMapPalette;

typedef struct _BitMapFileHeader{
	unsigned short bmfType;
	unsigned int bmfSize;
	unsigned short bmfRes1;
	unsigned short bmfRes2;
	unsigned int bmfOffBits;

	void getBMFHeader(std::istream &in);

} BMapFileHeader;

typedef struct _BitMapInfoHeader{
	unsigned int bmiSize;
	signed int bmiWidth;
	signed int bmiHeight;
	unsigned short bmiPlanes;
	unsigned short bmiBitCount;
	unsigned int bmiCompression;
	unsigned int bmiSizeImage;  //д.б. 0, если bmiCompression = BI_RGB;
	signed int bmiXPelsPerMeter;
	signed int bmiYPelsPerMeter;
	unsigned int bmiClrUsed;
	unsigned int bmiClrImportant;
	
	void getBMIHeader(std::istream &in);

} BMapInfoHeader;



class BitMapClass
{
	BMapFileHeader *f_header;
	BMapInfoHeader *i_header;
	BMapPalette *palette;   //палитра для палитрового вывода
	//Plane *plane;     //цвета пикселей
	Plane *plane;
	int x_size;
	int y_size;
public:
	 explicit BitMapClass(std::istream &in);
	 explicit BitMapClass(QString f_name);
	 void getBMapPallette(std::istream &in);
	 void getPicturePlane(std::istream &in);
	 Plane* getPlane(void) { return plane; }
	 int getX(void) { return x_size; }
	 int getY(void) { return y_size; }
	 QByteArray file_array;
	~BitMapClass();
};

