
#ifndef PLAYER_H
#define PLAYER_H

#include "Talk.h"

#include <fstream>

class Player {
    public:
        Player();

        virtual void play(const Talk& m, ostream& ost) const = 0;
        virtual ~Player() = default;
};


class AudioPlayer : public Player {
    public:
        void play(const Talk& m, ostream& ost) const override;
};


class VideoPlayer : public AudioPlayer {
    public:
        void play(const Talk& m, ostream& ost) const override;
};



#endif