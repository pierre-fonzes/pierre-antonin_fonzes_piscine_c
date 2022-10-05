typedef struct linkedList linkedList;
struct linkedList{
	void *data;//donnée du maillon
	linkedList * next;//pointeur vers le prochain élément
};
