#include "control.h"

Control::Control(Kid* k)
{

    kid = k;

    MIN_HEIGHT = 0.8;
    MAX_HEIGHT = 1.3;
    MIN_WIDTH = 0.8;
    MAX_WIDTH = 1.3 ;
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
        if((kid->getStart_height()*MAX_HEIGHT < kid->getHeight()) && (kid->getStart_width()*MAX_WIDTH < kid->getWidth())){

            //SE O ROBO ESTIVER INDO PARA FRENTE OU RODANDO, ELE PARA
            if(moving_forward || rotating_left || rotating_right){
                stop();
                return STOP;
            }else{

                //SE O ROBO NÃO ESTIVER INDO PARA TRÁS, VAI PARA TRÁS
                if(!moving_backward){
                    move(MOVE_BACKWARD);
                    return MOVE_BACKWARD;
                }else{

                    //SE O ALVO ESTIVER DESLOCADO PARA ESQUERDA
                    if( (kid->getScreen_width()/2)*MIN_X_VARIATION > kid->getX() ){
                        //SE O ROBO ESTIVER INDO PARA DIREITA PARA
                        if(moving_right){
                             stop();
                            return STOP;
                        } else {
                            //SE O ROBO NÃO ESTIVER INDO PARA ESQUERDA, VAI PARA ESQUERDA
                            if(!moving_left){
                                move(MOVE_LEFT);
                                return MOVE_LEFT;
                            } else {
                                return STAY;
                            }

                        }
                    }else{
                        //SE O ALVO ESTIVER DESLOCADO PARA A DIREITA
                        if( (kid->getScreen_width()/2)*MAX_X_VARIATION < kid->getX() ){
                            //SE O ROBO ESTIVER INDO PARA A ESQUERDA
                            if(moving_left){
                                stop();
                                return STOP;
                            } else {
                                //SE O ROBO NÃO ESTIVER INDO PARA A DIREITA
                                if(!moving_right){
                                    move(MOVE_RIGHT);
                                    return MOVE_RIGHT;
                                }else{
                                    return STAY;
                                }
                            }

                        }else{
                            return STAY;
                        }

                    }
                }
            }
        } else {

            //SE O ALVO ESTIVER LONGE
            if((kid->getStart_height()*MIN_HEIGHT > kid->getHeight()) && (kid->getStart_width()*MIN_WIDTH > kid->getWidth())){

                //SE O ALVO ESTIVER INDO PARA TRÁS OU GIRANDO
                if(moving_backward || rotating_left || rotating_right){
                    stop();
                    return STOP;
                }else{

                    //SE O ALVO NÃO ESTIVER INDO PARA FRENTE
                    if(!moving_forward){
                        move(MOVE_FORWARD);
                        return MOVE_FORWARD;
                    }else{
                        //SE O ALVO ESTIVER SE DESLOCANDO PARA A ESQUERDA
                        if( (kid->getScreen_width()/2)*MIN_X_VARIATION > kid->getX() ){
                            //PARA O ROBO SE
                             if(moving_right){
                                stop();
                                return STOP;
                            } else{
                                //SE O ROBO NÃO ESTIVER GIRANDO PARA ESQUERDA, VAI PARA ESQUERDA
                                if(!moving_left){
                                    move(MOVE_LEFT);
                                    return MOVE_LEFT;
                                }else{
                                    return STAY;
                                }
                            }
                        }else{

                            //SE O ALVO ESTIVER DESLOCADO PARA A DIREITA
                            if( (kid->getScreen_width()/2)*MAX_X_VARIATION < kid->getX() ){
                                 //SE O ROBO ESTIVER INDO PARA A ESQUERDA
                                if(moving_left){
                                    stop();
                                    return STOP;
                                }else{
                                    //SE O ROBO NÃO ESTIVER INDO PARA A DIREITA
                                    if(!moving_right){
                                        move(MOVE_RIGHT);
                                        return MOVE_RIGHT;
                                    }else{
                                        return STAY;
                                    }
                                }
                            }else{
                                return STAY;
                            }
                        }

                    }
                }
            }else{
                //SE O ALVO ESTIVER DESLOCADO PARA DIREITA
                if( (kid->getScreen_width()/2)*MAX_X_VARIATION < kid->getX() ){
                    //SE ELE ESTIVER SE MOVENDO OU RODANDO NO OUTRO SENTIDO
                    if(moving_forward || moving_backward || moving_left || moving_right || rotating_left){
                        stop();
                        return STOP;
                    }else{
                        //SE ELE NÃO ESTIVER RODANDO
                        if(!rotating_right){
                            move(ROTATE_RIGHT);
                            return ROTATE_RIGHT;
                        }else{
                            return STAY;
                        }
                    }
                }else{
                    //SE O ALVO ESTIVER DESLOCADO PARA A ESQUERDA
                    if( (kid->getScreen_width()/2)*MIN_X_VARIATION > kid->getX() ){
                        //SE ELE ESTIVER SE MOVENDO OU RODANDO NO OUTRO SENTIDO
                        if(moving_forward || moving_backward || moving_left || moving_right || rotating_right){
                            stop();
                            return STOP;
                        }else{
                            //SE ELE NÃO ESTIVER GIRANDO
                            if(!rotating_left){
                                move(ROTATE_LEFT);
                                return ROTATE_LEFT;
                            }else{
                                return STAY;
                            }
                        }
                    }else{
                        //SE O ROBO ESTIVER SE MOVENDO
                        if(moving_forward || moving_backward || moving_left || moving_right || rotating_left || rotating_right){
                            stop();
                            return STOP;
                        }else{
                            return STAY;
                        }
                    }
                }
            }


     }

    }else{
        //SE NÃO ENCONTRAR O ALVO
        lost = true;
        if(moving_forward || moving_backward || moving_left || moving_right || rotating_right){
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
