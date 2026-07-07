#include <ctime>
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
// Project(2) Math Test

int MistakesCounter = 0, CorrectCounter = 0;

enum EnDiffiuclty { easy = 1, mid = 2, hard = 3, mixed = 4 };
enum EnOperationType { addition = 1, subtraction = 2, multiblication = 3, divison = 4, mix = 5 };

int readNumberOfQuestoins() {
    int num;
    do {
        cout << "How many questions do you want ?\n";
        cin >> num;
    } while (num <= 0);
    return num;
}

int genrateRandom(int From, int To) {
    return rand() % (To - From + 1) + From;
}

struct stTest {
    EnDiffiuclty TestDiffiuclty;
    EnOperationType TestOperations;
    int numberOfQuestions;
};

EnDiffiuclty getDiffiuclty(int choice) {
    return EnDiffiuclty(choice);
}
EnOperationType getOperation(int choice) {
    return EnOperationType(choice);
}


int GenrateEasyNumbers() {
    return genrateRandom(1, 10);
}
int genrateMidNumbers() {
    return genrateRandom(11, 40);
}
int genrateHardNumbers() {

    return genrateRandom(41, 100);
}

EnDiffiuclty genrateMixedDifficulty() {
    return EnDiffiuclty(genrateRandom(1, 3));
}
EnOperationType genrateMixedOperation() {
    return EnOperationType(genrateRandom(1, 4));
}


void cheakAnswer(int answer, int result) {
    
    if (answer == result) {
        cout << "Right answer :-)" << endl<<endl;
        ::CorrectCounter++;
        system("color 2F");
    }
    else
    {
        cout << "Wrong answer :-(\n";
        cout << "The right answer is : " << result << endl << endl;
        system("color 4F");
        ::MistakesCounter++;
    }
}

void doAdditonOperation(int num1, int num2) {
    int result, answer;
    result = num1 + num2;
    cout << num1 << "\n" << num2 << " +\n-----------\n>- ";
    cin >> answer;
    cheakAnswer(answer, result);


}

void doSubtractionOperation(int num1, int num2) {
    int result, answer;
    result = num1- num2;
    cout << num1 << "\n" << num2 << " -\n-----------\n>- ";
    cin >> answer;
    cheakAnswer(answer, result);
}
void doMultiblicationOperation(int num1, int num2) {
    int result, answer;
    result = num1 * num2;
    cout << num1 << "\n" << num2 << " X\n-----------\n>- ";
    cin >> answer;
    cheakAnswer(answer, result);

}
// currently division questions return integer results only
// this will be improved later when the program is expanded
void doDivisonOperation(int num1, int num2) {
    int result, answer;
    result = num1 / num2;
    cout << num1 << "\n" << num2 << " /\n-----------\n>- ";
    cin >> answer;
    cheakAnswer(answer, result);
}
void GenrateEasyQuestions(EnOperationType OperationType) {

    int num1 = GenrateEasyNumbers(), num2 = GenrateEasyNumbers();


    if (OperationType == addition)
    {
        doAdditonOperation(num1, num2);
    }
    else if (OperationType == subtraction) {

        doSubtractionOperation(num1, num2);
    }
    else if (OperationType == multiblication) {
        doMultiblicationOperation(num1, num2);

    }
    else if (OperationType == divison) {

        doDivisonOperation(num1, num2);

    }
    else {
        GenrateEasyQuestions(genrateMixedOperation());
    }


}
void GenrateMidQuestions(EnOperationType OperationType) {
    int num1 = genrateMidNumbers(), num2 = genrateMidNumbers();


    if (OperationType == addition)
    {
        doAdditonOperation(num1, num2);
    }
    else if (OperationType == subtraction) {

        doSubtractionOperation(num1, num2);
    }
    else if (OperationType == multiblication) {
        doMultiblicationOperation(num1, num2);

    }
    else if (OperationType == divison) {

        doDivisonOperation(num1, num2);

    }
    else {
        GenrateMidQuestions(genrateMixedOperation());
    }

}
void GenrateHardQuestions(EnOperationType OperationType) {
    int num1 = genrateHardNumbers(), num2 = genrateHardNumbers();


    if (OperationType == addition)
    {
        doAdditonOperation(num1, num2);
    }
    else if (OperationType == subtraction) {

        doSubtractionOperation(num1, num2);
    }
    else if (OperationType == multiblication) {
        doMultiblicationOperation(num1, num2);

    }
    else if (OperationType == divison) {

        doDivisonOperation(num1, num2);

    }
    else {
        GenrateHardQuestions(genrateMixedOperation());
    }
}
void GenrateMixedQuestions(EnOperationType OperationType) {
    EnDiffiuclty Diffuclity = genrateMixedDifficulty();
    if (Diffuclity == hard)
        GenrateHardQuestions(OperationType);
    else
        if (Diffuclity == mid)
            GenrateMidQuestions(OperationType);
        else
            if (Diffuclity == easy)
                GenrateEasyQuestions(OperationType);

}
string isPass(int corrctAns, int WrongAns) {
    if (corrctAns >= WrongAns)
        return "Pass";
    return "Fail";

}
stTest ReadOpetions() {
    int DiffiucltyChoice, OperationChoice; stTest TestInfo;
    TestInfo.numberOfQuestions = readNumberOfQuestoins();

    cout << "Enter Questions Level [1] Easy ,[2] Mid ,[3] Hard ,[4] Mix ? ";
    cin >> DiffiucltyChoice;
    TestInfo.TestDiffiuclty = getDiffiuclty(DiffiucltyChoice);

    cout << "Enter Operation Type [1] Add ,[2] Subtraction ,[3] Multiblication ,[4] Divsion ,[5] mix ? ";
    cin >> OperationChoice;
    TestInfo.TestOperations = getOperation(OperationChoice);

    return TestInfo;
}

string printDiffuicltyType(EnDiffiuclty en) {
    if (en == hard)
        return"hard";
    else
        if (en == mid)
            return "mid";
        else
            if (en == easy)
                return "easy";
            else
                return "mix";
}
string printOperationType(EnOperationType en) {
    if (en == addition)
        return "additon";
    else
        if (en == subtraction)
            return "subratction";
        else
            if (en == multiblication)
                return "multiblication";
            else
                if (en == divison)
                    return "Divison";
                else
                    return "mix";
}
void displayExamInfo(int NumberOfQuestions, EnDiffiuclty diffiuclty, EnOperationType optype, int NumberOfCorrectAns, int NumberOFWrongAns) {
    
    cout << "\nNumber Of Questions :" << NumberOfQuestions << endl;
    cout << "Questions Level : "<< printDiffuicltyType (diffiuclty) << endl;
    cout << "Operation type : " << printOperationType(optype) << endl;
    cout << "Number of correct answers :" << NumberOfCorrectAns << endl;
    cout << "Number of wrong answers :" << NumberOFWrongAns << endl;

}

void reset() {

    system("cls");
    system("color 0F");
    ::CorrectCounter = 0; ::MistakesCounter = 0;
}
void genrateExam(stTest Test) {
   
    


        for (int i = 1; i <= Test.numberOfQuestions; i++) {
            cout << "Question [" << i << "/" << Test.numberOfQuestions << "]\n\n";
            if (Test.TestDiffiuclty == hard) {
                GenrateHardQuestions(Test.TestOperations);
            }
            else if (Test.TestDiffiuclty == mid) {
                GenrateMidQuestions(Test.TestOperations);
            }
            else if (Test.TestDiffiuclty == easy) {
                GenrateEasyQuestions(Test.TestOperations);
            }
            else {
                GenrateMixedQuestions(Test.TestOperations);
            }

        }
        cout << "\n------------------------------------\n";
        cout << "\tFinal Result is " << isPass(CorrectCounter, MistakesCounter) << endl;
        cout << "\n-------------------------------------\n\n";
        displayExamInfo(Test.numberOfQuestions, Test.TestDiffiuclty, Test.TestOperations, CorrectCounter, MistakesCounter);
        cout << "\n------------------------------------\n";
        


    }
void startMathExam() {
    char reapet;
    do {
        reset();
        genrateExam(ReadOpetions());
        
            cout << "\n\n\t\tdo you want to continue Y/N ? ";
            cin >> reapet;
          


    } while (reapet == 'y' || reapet == 'Y');

}

int main()
{
    srand((unsigned)time(NULL));
    startMathExam();
   
}

