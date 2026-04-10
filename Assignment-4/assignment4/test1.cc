

#include "Search.h"
#include "Talk.h"
#include "Conference.h"
#include "Player.h"
#include "SummitStream.h"
#include "List.h"

int main() {

    // S_Search newSearch("Evan");

    Talk newTalk("title", "Evan", "k1, ,k2, k3", "p3", "batman.txt");

    // cout << newSearch.matches(&newTalk) << endl;

    Conference conf("Gala", "gobber gaba");

    conf.add(&newTalk);

    // cout << *conf.getTalk(1) << endl;

    VideoPlayer ap;

    // cout << newTalk.getAudio() << endl;

    // ap.play(newTalk, cout);

    SummitStream ss;

    ss.addConference(&conf);

    ss.addTalk(&newTalk, "Gala");


    ss.getConference(0);

    // cout << *(ss.getConference(1));


    S_Search s("Ean");

    List<Talk*> talk_list;

    ss.getTalks(s, talk_list);

    for (int i = 0; i < talk_list.getSize(); i++) {
        cout << (*talk_list[i]);
    }

    return 0;
}
