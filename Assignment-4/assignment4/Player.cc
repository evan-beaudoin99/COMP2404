

#include "Player.h"


Player::Player() {}

void AudioPlayer::play(const Talk& m, ostream& ost) const {
    ost << m.getAudio() << endl;
}


void VideoPlayer::play(const Talk& m, ostream& ost) const {
    AudioPlayer::play(m, ost);

    ifstream file(m.getVideoFile());
    string line;
    while (getline(file, line)) {
        ost << line << endl;
    }
}