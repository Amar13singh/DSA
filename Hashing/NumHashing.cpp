#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

//input  as string ignore everything except numbers...
//stop reading as space encounters....
//input as 1234567890
int main(){
    // int n;  //size of array
    // std::cout<<"Enter the size of the array: ";
    // std::cin>>n;
    // int arr[n];        
    // for(int i=0;i<n;i++){
    //     std::cout<<"Enter the element "<<i+1<<": ";
    //     std::cin>>arr[i];  //input array
    //taking input of array dynamically using vector..
    std::vector<int> arr;
    std::string input;
    std::cout<<"Enter numbers(type -1 to stop): ";
    std::cin>>input;
   
    // Process each character separately
    for (char ch : input) {
        // if (ch == '-') break;  // Stop if '-' is encountered //not needed as we are using string
        if (isdigit(ch)) {     // Ensure it's a digit before converting
            arr.push_back(ch - '0');  // Convert character to integer
        }
    }

    // //precompute the hash array
    // int hash[13]={0};
    // for(int i=0;i<arr.size();i++){
    //     hash[arr[i]]++;
    // }

    // Precompute frequency using an unordered_map
    std::unordered_map<int, int> hash1;
    for (int i = 0; i < arr.size(); i++) {
        hash1[arr[i]]++;
    }

    //queries for the number of occurences
    int q;
    std::cout<<"Enter the number of queries: ";
    std::cin>>q;
    while(q--){
        int number;
        std::cout<<"Enter the number: ";
        std::cin>>number;
        // std::cout<<hash1[number]<<std::endl;
    

     // Check if the number exists in the map
     if (hash1.find(number) != hash1.end()) {
        std::cout << hash1[number] << std::endl;
    } else {
        std::cout << "0" << std::endl;
    }

}




    return 0;
}