#ifndef MOVEMENT_MODE_H
#define MOVEMENT_MODE_H

#define CASE_MOVEMENT(l, d, u, r) \
    case l: \
        loginfo("left"); \
        editor_toleft(); \
        break; \
    case d: \
        loginfo("down"); \
        editor_todown(); \
        break; \
    case u: \
        loginfo("up"); \
        editor_toup(); \
        break; \
    case r: \
        loginfo("right"); \
        editor_toright(); \
        break; \

#define HOMEND_MOVEMENT \
    case KEY_HOME: \
        loginfo("home"); \
        editor_tohome(); \
        break; \
    case KEY_END: \
        loginfo("end"); \
        editor_toend(); \
        break; \
    case KEY_SHOME: \
        loginfo("start"); \
        editor_tostart(); \
        break; \
    case KEY_SEND: \
        loginfo("finish"); \
        editor_tofinish(); \
        break;

#define MATCH_MOVEMENT \
    case '[': \
        loginfo("["); \
        editor_toprvmatch(); \
        break; \
    case ']': \
        loginfo("]"); \
        editor_tonxtmatch(); \
        break; \

#define ARROW_MOVEMENT      CASE_MOVEMENT(KEY_LEFT, KEY_DOWN, KEY_UP, KEY_RIGHT)
#define VIM_MOVEMENT        CASE_MOVEMENT('h', 'j', 'k', 'l')

#define CHAR_MOVEMENT       VIM_MOVEMENT MATCH_MOVEMENT
#define NONCHAR_MOVEMENT    ARROW_MOVEMENT HOMEND_MOVEMENT

#endif
