#include<iostream> 
#include<vector>

using namespace std; 

void groupElements(int arr[], int n) { 
	bool *seen = new bool[n]; 
	for (int i=0; i<n; i++) 
		seen[i] = false; 

	// Traverse all elements 
	for (int i=0; i<n; i++) { 
		// Check if this is first time 
		if (!seen[i]) { 
			cout << arr[i] << " "; 
			for (int j=i+1; j<n; j++) { 
				if (arr[i] == arr[j]) { 
					cout << arr[i] << " "; 
					seen[j] = true; 
				} 
			} 
		} 
	} 

	delete [] seen; 
} 

int main() { 
	vector<int> arr = { 1,3,2,4,1,4,4 }; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	groupElements(arr, n); 
	return 0;
}