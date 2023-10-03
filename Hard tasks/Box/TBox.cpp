#include "TBox.h"


float TBox::SizeX()
{	return bx;}
float TBox::SizeY()
{	return by;}
float TBox::SizeZ()
{	return bz;}
float TBox::Volume()
{	return bx * by * bz;}
TBox& TBox::SizeX(float x)
{	bx = x; return *this;}
TBox& TBox::SizeY(float y)
{	by = y; return *this;}
TBox& TBox::SizeZ(float z)
{	bz = z; return *this;}
int TBox::HowMachTkInside(TBox& Box)
{
	int kol, k;
	k = floor(bx / Box.bx) * floor(by / Box.by) * floor(bz / Box.bz);				 kol = k;
	k = floor(bx / Box.bx) * floor(by / Box.bz) * floor(bz / Box.by);	if (k > kol) kol = k;
	k = floor(bx / Box.by) * floor(by / Box.bx) * floor(bz / Box.bz);	if (k > kol) kol = k;
	k = floor(bx / Box.by) * floor(by / Box.bz) * floor(bz / Box.bx);	if (k > kol) kol = k;
	k = floor(bx / Box.bz) * floor(by / Box.bx) * floor(bz / Box.by);	if (k > kol) kol = k;
	k = floor(bx / Box.bz) * floor(by / Box.by) * floor(bz / Box.bx);	if (k > kol) kol = k;
	return kol;
}
void TBox::Print()
{
	cout << this->SizeX() << "x" << this->SizeY() << "x" << this->SizeZ();
}
TBox& TBox::BoxResize(float x, float y, float z)
{
	bx = x; by = y; bz = z;
	return *this;
}