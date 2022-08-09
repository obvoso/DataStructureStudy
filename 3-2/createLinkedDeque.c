#include "simdef.h"

LinkedDeque* createLinkedDeque()
{
	LinkedDeque *ret;

	ret = (LinkedDeque *)malloc(sizeof(LinkedDeque));
	if (!ret)
		return (NULL);
	ret->currentElementCount = 0;
	ret->pFrontNode = NULL;
	ret->pRearNode = NULL;
	return (ret);
}
