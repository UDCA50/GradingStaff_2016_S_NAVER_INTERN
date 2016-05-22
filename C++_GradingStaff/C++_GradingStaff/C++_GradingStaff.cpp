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
#include<cstring>

int errorHandling_IO(int argc, char** argv){

	int digIter = 0;
	int numberLength = strlen(argv[1]);

	if (argc < 2){ std::cout << "[error 001] : invaild input ";  return 0; }
	else if (argc >= 3){ std::cout << "[error 002] : invaild input"; return 0; }
	
	for (digIter = 0; digIter < numberLength; digIter){
		if (isdigit(argv[1][digIter] == 0)) {
			std::cout << "[error 003] :invaild input";
			return 0;
		}
	}

	return 1;

}

int printHelp(int errorCode){
	//에러 코드에 따라 help를 bold 하여 출력
}

int main(int argc, char** argv){
	if ((errorHandling_IO(argc, argv))){
		//making Staff number
	}


	return 1;

}