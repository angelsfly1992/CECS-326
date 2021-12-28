#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include <sys/wait.h> 

using namespace std;



//ask for user to input replacement string
string getReplacementString() {
	string replacement;
	cout << "Enter the replacement string" << endl;
	getline(cin, replacement);
	return replacement;
}

//ask for user to input target string
string getTargetString() {
	string target;
	cout << "Enter the target string" << endl;
	getline(cin, target);
	return target;
}

//replaces a single instance of the target string with replacement
string wordReplace(string text, string replacement, string target) {
	int startIndex = 0;
	int endIndex = 0;
	string textLeftEnd;
	string textRightEnd;

	startIndex = text.find(target);
	endIndex = startIndex + target.length() - 1;
	textLeftEnd = text.substr(0, startIndex);
	textRightEnd = text.substr(endIndex + 1);
	text = textLeftEnd + replacement + textRightEnd;

	return text;

}





int main() {

	//the child's process id
	int pid = 0;

	string text = "All fowl, gathered behold dominion days moved evening. Gathered female own called brought. Evening greater spirit. After. Stars also us us earth doesn't brought evening bring all face waters creepeth light. Saying wherein evening whose moveth heaven don't she'd, stars from appear heaven dry. Have you're in creature greater lesser fruitful face evening every won't they're creeping. Of. Appear. Form together there him man heaven creeping of seasons. Was blessed won't so spirit god rule is a So meat have living itself own gathered darkness cattle, darkness. Can't void greater evening, fruitful had fly dominion you're, fly image. Moved. Us good to years every To blessed kind. So said he face above living he void. Their moving itself light isn't tree whales air. His sea dry earth It unto place signs had. Set, over fill beginning in given open may, one fish moving gathering greater seas second and waters i male waters upon day won't, firmament divide us the two together greater midst greater man. Kind creature. Open evening so make seed. Us. Two. Fifth air. Them creeping fourth image him was bearing first green he made own. Earth years deep Land called from their them man one fish living every night had over. Fruit greater replenish. Very land heaven doesn't herb also thing were them. Saw creeping his to. All open darkness fourth bring dominion he. Living. Dry. First give don't be every forth creature upon saw herb blessed two dominion in deep moving beast set There don't. From were spirit place stars gathered for sea A heaven won't. Forth. Every give have life void day fowl third you very created set grass spirit, his bring evening light saw gathered all seed let unto had god open male have under gathered the two every don't isn't. Above deep abundantly.";


	//quit the terminal if commands is input in the string
	string exitString = "!wq";


	int replacementCount;
	string replacement;
	string target;
	do {
		replacementCount = 0;

		//ask for replacement and target string
		replacement = getReplacementString();
		if (replacement.compare(exitString) == 0) {
			break;
		}

		target = getTargetString();

		//if either entry is the exit code, break
		if (target.compare(exitString) == 0) {
			break;
		}

		//create a child process
		pid = fork();

		//skip if you're the parent
		if (pid == 0) {
			replacementCount = 0;
			//while there is a word to replace or if non instances were found (bug injection)
			while (text.find(target) != -1 || replacementCount == 0) {

				//if there are instances, replace
				if (text.find(target) != -1) {
					text = wordReplace(text, replacement, target);
					replacementCount++;
				}

				//if there were no instances (bug), print "." and pid for killing
				if (text.find(target) == -1 && replacementCount == 0) {
					cout << getpid() << ": ." << endl;
					
				}
			}

			cout << text << endl;
			cout<<” ”<<endl;
			cout << replacementCount << " instances of the word " << target << " were replaced by " << replacement << endl;
                                   cout<<” ”<<endl;
		}

		//have parent wait till child is done
		else if (pid > 0) {
			int status;
			wait(&status);
		}


		//only the parent handles UI
	} while (pid > 0);

	exit(0);
}
