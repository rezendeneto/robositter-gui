#include "control.h"

Control::Control(Kid* k)
{

    kid = k;

    MIN_HEIGHT = 0.8;
    MAX_HEIGHT = 1.2;
    MIN_WIDTH = 0.8;
    MAX_WIDTH = 1.2 ;
    MIN_X_VARIATION = 0.8;
    MAX_X_VARIATION = 1.2;

    stop();
    lost = false;
}

int Control::action(){
    if(!kid->getLost()){
        if(lost){
            stop();
            lost = false;
            return STOP;
        }
        //SE O ALVO ESTIVER MUITO PERTO
        if(aumentou()){
            if(moving_forward){
                stop();
                return STOP;
            }else{
                if(direita()){
                    if(rotating_left || moving_backward){
                        stop();
                        return STOP;
                    }else{
                        if(!rotating_right){
                            move(ROTATE_RIGHT);
                            return ROTATE_RIGHT;
                        }else{
                            return STAY;
                        }
                    }
                }else{
                    if(esquerda()){
                        if(rotating_right || moving_backward){
                            stop();
                            return STOP;
                        }else{
                            if(!rotating_left){
                                move(ROTATE_LEFT);
                                return ROTATE_LEFT;
                            }else{
                                return STAY;
                            }
                        }
                    }else{
                        if(rotating_left || rotating_right){
                            stop();
                            return STOP;
                        }else{
                            if(!moving_backward){
                                move(MOVE_BACKWARD);
                                return MOVE_BACKWARD;
                            }else{
                                return STAY;
                            }
                        }
                    }

                }
            }
        }else{
            if(diminuiu()){
                if(moving_backward){
                    stop();
                    return STOP;
                }else{
                    if(direita()){
                        if(rotating_left || moving_forward){
                            stop();
                            return STOP;
                        }else{
                            if(!rotating_right){
                                move(ROTATE_RIGHT);
                                return ROTATE_RIGHT;
                            }else{
                                return STAY;
                            }
                        }
                    }else{
                        if(esquerda()){
                            if(rotating_right || moving_forward){
                                stop();
                                return STOP;
                            }else{
                                if(!rotating_left){
                                    move(ROTATE_LEFT);
                                    return ROTATE_LEFT;
                                }else{
                                    return STAY;
                                }
                            }
                        }else{
                            if(rotating_left || rotating_right){
                                stop();
                                return STOP;
                            }else{
                                if(!moving_forward){
                                    move(MOVE_FORWARD);
                                    return MOVE_FORWARD;
                                }
                            }
                        }
                    }
                }
            }else{
                if(moving_forward || moving_backward){
                    stop();
                    return STOP;
                }else{
                    if(direita()){
                        if(rotating_left){
                            stop();
                            return STOP;
                        }else{
                            if(!rotating_right){
                                move(ROTATE_RIGHT);
                                return ROTATE_RIGHT;
                            }else{
                                return STAY;
                            }
                        }
                    }else{
                        if(esquerda()){
                            if(rotating_right){
                                stop();
                                return STOP;
                            }else{
                                if(!rotating_left){
                                    move(ROTATE_LEFT);
                                    return ROTATE_LEFT;
                                }else{
                                    return STAY;
                                }
                            }
                        }else{
                            if(moving_forward || moving_backward || rotating_left || rotating_right){
                                stop();
                                return STOP;
                            }else{
                                return PING;
                            }
                        }
                    }
                }
            }
        }



    }else{
        //SE NAO ENCONTRAR O ALVO
        lost = true;
        if(moving_forward || moving_backward || moving_left || moving_right || rotating_left){
            stop();
            return STOP;
        }else{
            if(!rotating_right){
                move(ROTATE_RIGHT);
                return ROTATE_RIGHT;
            }else{
                return STAY;
            }
        }
    }

    return STAY;
}

void Control::stop(){
    moving_forward = false;
    moving_backward = false;
    moving_left = false;
    moving_right = false;
    rotating_left = false;
    rotating_right = false;
}

void Control::move(int m){
    switch(m){
        case(MOVE_FORWARD):
            moving_forward = true;
            break;
        case(MOVE_BACKWARD):
            moving_backward = true;
            break;
        case(MOVE_LEFT):
            moving_left = true;
            break;
        case(MOVE_RIGHT):
            moving_right = true;
            break;
        case(ROTATE_LEFT):
            rotating_left = true;
            break;
        case(ROTATE_RIGHT):
            rotating_right = true;
            break;
        default:
            break;
    }
}

bool Control::diminuiu(){
    if(kid->getHeight() < kid->getStart_height()*MIN_HEIGHT && kid->getWidth() < kid->getStart_width()*MIN_WIDTH){
        return true;
    }else{
        return false;
    }
}

bool Control::aumentou(){
    if((kid->getHeight() > (kid->getStart_height()*MAX_HEIGHT)) && (kid->getWidth() > (kid->getStart_width()*MAX_WIDTH))){
        return true;
    }else{
        if( (kid->getY()-(kid->getHeight()/2) < 1) || (kid->getY()+(kid->getHeight()/2) >= kid->getScreen_height())){
            if( kid->getWidth() > (kid->getStart_width()*MAX_WIDTH) ){
                return true;
            }else{
                return false;
            }
        }else{
            return false;
        }
    }
}

bool Control::direita(){
    if( (kid->getScreen_width()/2)*MAX_WIDTH < kid->getX() ){
        return true;
    }else{
        return false;
    }
}

bool Control::esquerda(){
    if( (kid->getScreen_width()/2)*MIN_WIDTH > kid->getX() ){
        return true;
    }else{
        return false;
    }
}
