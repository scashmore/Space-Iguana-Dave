#include "Story.h"
#include "Scene.h"
#include <iostream>

std::vector<Scene*> createStory() {
    // Create the initial scene
    Scene* start = new Scene("Dave finds himself floating in space, wondering what to do next.", 
                              {"Fight a Space Seagull", "Search for Chill Crystals", "Take a nap"});

    // Create outcomes for choices
    Scene* fight = new Scene("Dave faces a giant Space Seagull! The seagull squawks, 'You will never stop my seagull army!'",
                              {"Blast it with the Banana Blaster", "Run away"});
    Scene* search = new Scene("Dave floats aimlessly and finds nothing but space dust. Suddenly, a message pops up: 'No chill crystals here!'", 
                               {"Give up", "Try a different galaxy"});
    Scene* nap = new Scene("Dave falls asleep and dreams of a world where iguanas rule the universe. The end.", 
                           {"Wake up", "Keep dreaming"});

    // Add outcomes to the start scene
    start->addOutcome(fight);
    start->addOutcome(search);
    start->addOutcome(nap);

    // Add placeholder outcomes to fight/search/nap
    Scene* end1 = new Scene("The Space Seagull is no match for your fruity fury. It explodes into a burst of cosmic feathers.", {});
    Scene* end2 = new Scene("You run away. The seagull mocks you from space. But hey, you're alive.", {});
    fight->addOutcome(end1);
    fight->addOutcome(end2);

    Scene* end3 = new Scene("You give up. That's okay. Space is hard.", {});
    Scene* end4 = new Scene("You zip to another galaxy and find the elusive Chill Crystals!", {});
    search->addOutcome(end3);
    search->addOutcome(end4);

    Scene* end5 = new Scene("Dave wakes up refreshed... but slightly stickier than before.", {});
    Scene* end6 = new Scene("Dave dreams forever. Eventually, he becomes Dream Emperor Dave.", {});
    nap->addOutcome(end5);
    nap->addOutcome(end6);

    return {start, fight, search, nap}; // Return a list of all scenes
}