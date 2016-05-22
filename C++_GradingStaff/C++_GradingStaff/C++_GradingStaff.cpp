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


//오류 처리 001 : 프로그램 실행시 숫자가 입력되지 않는경우 => --help 출력 유도
//오류 처리 002 : 프로그램 실행시 인자가 2개이상 들어오는 경우 =>  --help 출력 유도
//오류 처리 003 : 프로그램 실행시 입력이 숫자가 아닌경우 ==> --help 출력 유도
//오류 처리 004 : 프로그램 실행시 숫자가 0이나 음의 정수로 입력되는경우 => --help 출력 유도

#include<iostream>
#include<cctype>
#include<string>
#include<vector>

#define STAFF_NUM_SIZE 99999

int errorHandling_Para(int argc, char** argv){

	int digIter = 0;
	
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
	//[error 004]
	if (std::stoi(argv[1], nullptr) <= 0){
		std::cout << "[error 004] :invaild input\n";
		return 0;
	}

	return 1;

}

//make lookupTable 
// 추가적으로 점수를 저장할 필요가 있다면 => vector 를 hashmap 으로 변환
std::vector<int>* makeLUT(){
	std::vector<int>* numberLUT = new std::vector<int>;
	for (int i = 0; i <= STAFF_NUM_SIZE; i++){
		numberLUT->push_back(i);
	}
	return numberLUT;

}
//난수로 사번생성
int generateRand(){

}
int printHelp(int errorCode){
	//에러 코드에 따라 help를 bold 하여 출력
	return 0;
}

	


int main(int argc, char** argv){

	//parameter error handle
	if ((errorHandling_Para(argc, argv))){
	

		//make LUT
		std::vector<int>* numberLUT = makeLUT();

		//access randomly
	}



	return 1;

}