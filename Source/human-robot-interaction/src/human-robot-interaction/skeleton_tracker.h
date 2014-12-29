/**
 * Author: Aravinth Panchadcharam
 * Email: me@aravinth.info
 * Date: 29/12/14.
 * Project: Gesture Recogntion for Human-Robot Interaction
 */

#ifndef __human_robot_interaction__skeleton_tracker__
#define __human_robot_interaction__skeleton_tracker__

#include "NiTE.h"
#include "udp_server.h"

class skeleton_tracker
{
private:
    int MAX_USERS = 2;
    nite::UserTracker userTracker;
    nite::Status niteRc;
    udp_server *server_;
    
    void init_nite();
    void track_skeleton();
    void update_user_state(const nite::UserData& user);
    
public:
    skeleton_tracker(udp_server *server);
    void run();
};

#endif
