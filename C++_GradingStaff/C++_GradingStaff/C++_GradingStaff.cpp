// 사원번호 출력프로그램
// 20160522 작성

// 입력 : 0이상 숫자 
// 출력 : 사원번호 성적

/* 조건일람
* 사원번호는 NT는 바꿀수 없고
* 뒤의 다섯자리는 random 숫자
* random 값이 99999 이하면 0으로 채움 (30이라면 NT00030)
* 사원번호 중복 안됨.
* score는 0점이상 100점 미만
*/

//예외 처리 : 사원의 숫자가 5이상인 경우 => 5개 마다 줄바꿈 출력

//오류 처리 001 : 프로그램 실행시 숫자가 입력되지 않는경우
//오류 처리 002 : 프로그램 실행시 인자가 2개이상 들어오는 경우
//오류 처리 003 : 프로그램 실행시 입력이 숫자가 아닌경우
//오류 처리 004 : 프로그램 실행시 숫자가 0이나 음의 정수이거나 입력이 99999를 넘어가는경우

#define _CRT_RAND_S
#define STAFF_NUM_SIZE 99999

#include<iostream>
#include<cctype>
#include<string>
#include<vector>
#include<random>
#include<cstdint>
#include<iomanip>
#include<climits>
#include<cstdlib>


int errorHandling_Para(int argc, char** argv){

	unsigned int digIter = 0;

	//[error 001]
	if (argc < 2){ std::cout << "[error 001] : invaild input\n";  return 0; }
	//[error 002]
	else if (argc >= 3){ std::cout << "[error 002] : invaild input\n"; return 0; }

	//[error 003]
	for (digIter = 0; digIter < strlen(argv[1]); digIter++){
		if (isdigit(argv[1][digIter]) == 0) {
			std::cout << "[error 003] :invaild input\n";
			return 0;
		}
	}
	int inputValue = std::stoi(argv[1], nullptr);
	//[error 004]
	if (inputValue <= 0 && inputValue>10000){
		std::cout << "[error 004] :invaild input\n";
		return 0;
	}

	return 1;

}

//make lookupTable 
// 추가적으로 점수를 저장할 필요가 있다면 => vector 를 hashmap 으로 변환
std::vector<int>* makeLUT(){
	std::vector<int>* numberLUT = new std::vector<int>;
	for (int i = 1; i <= STAFF_NUM_SIZE; i++){
		numberLUT->push_back(i);
	}
	return numberLUT;

}


//난수 생성 - s_rand 사용
int generateRand(int max){
	int i;
	unsigned int number;
	double maxi = max;
	errno_t err;
		err = rand_s(&number);
		return (double)number / ((double)UINT_MAX + 1) * maxi;
}

int generateNum(std::vector<int>* numberLUT){
	int i = 0;
	int j = 0;
	int gen_number = 0;
	int returnNumber = 0;
	gen_number = generateRand(numberLUT->size());
	returnNumber = numberLUT->at(gen_number);
	numberLUT->erase(numberLUT->begin() + gen_number);
	return returnNumber;
}
void printNumber(int generateNum){
	
}

int main(int argc, char** argv){


	//parameter error handle
	if ((errorHandling_Para(argc, argv))){

		//request number
		unsigned int requestNumber = std::stoi(argv[1], nullptr, 10);
		//make LUT
		std::vector<int>* numberLUT = makeLUT();

		//make Number & print Number
		int j = 0;
		for (j = 0; j < requestNumber; j++){
			std::cout <<"NT";
			std::cout << std::setfill('0') << std::setw(5);
			std::cout << generateNum(numberLUT) << " " << generateRand(99) << " ";
			if (j%5==4){
				std::cout << std::endl;
			}
		}

	}

	return 1;

}