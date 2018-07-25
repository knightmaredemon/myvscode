#include "List.h"

int main__()
{
	int a = 10;




	return 0;
}
int main__()
{


	List L = MakeEmpty();
	int i = 0;
	while (i < 5)
	{
		Insert(4 - i, L, L);
		i++;
	}
	Position P = First(L);
	Insert(10, L, P);
	Delete(10, L);
	Position PF = FindPrevious(3, L);
	DeleteList(L);
	return 0;
}

