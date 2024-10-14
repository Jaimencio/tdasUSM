// Swap two elements in a generic array
template<typename E>
void swap(E A[], int i, int j) {
	E temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}