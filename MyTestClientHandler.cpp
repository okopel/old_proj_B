
#include "MyTestClientHandler.h"
#include "Problem.h"
#include "Solution.h"

void MyTestClientHandler::handleClient() {

    string problem = "dfkgjkdlf";

    Problem *p = new Problem();
    Solution *s;
    if (this->cacheManager->isSolved(p)) {
        s = this->cacheManager->getSolution(p);
    } else {
        s = this->solver->solve(p);
    }

}
