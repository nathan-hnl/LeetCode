#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int numUniqueEmails(vector<string>& emails) {
    set<string> newEmails;
    string domain, local, new_email;
    for (string email: emails)
    {
        domain = email.substr(email.find("@"));
        local = email.erase(email.find("@"));
        local.erase(local.find("+"));
        local.erase(remove(local.begin(), local.end(), '.'), local.end());
        new_email = local + domain;
        newEmails.insert(new_email);
    }

    return newEmails.size();
}