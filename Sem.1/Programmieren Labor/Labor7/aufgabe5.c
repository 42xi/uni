// Sie schreiben nur die Funktion, keine Ausgabe!
#define PI 3.1415
void sphere(int rad, double *vol, double *sur)
{

    *vol = (4.0 / 3.0) * PI * (rad * rad * rad);
    *sur = 4.0 * PI * (rad * rad);
}
