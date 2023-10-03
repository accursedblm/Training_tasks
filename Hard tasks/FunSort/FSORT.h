#pragma once
#define CompFunc(F) bool (*F)(Ftype& A, Ftype& B, fWay way)
namespace FSORT
{
	struct Ftype {
		char Name[50];
		char Lastname[50];
		int Index;
	};
	enum fWay { fUp = 0, fDown };
	void FSort(Ftype* Ft, int d, CompFunc(F), fWay way = fUp);
	bool CompFtype(Ftype& A, Ftype& B, fWay way);
	void FtypeSwap(Ftype& A, Ftype& B);
}