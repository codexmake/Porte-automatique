void ouvrir_la_porte(){
  animations_ouvert_ar();
  Avancer();
  delay(delaimoteur);
  Stop();
  animation_att_ar();
  animations_fermer_ar();
  Reculer();
  delay(delaimoteur);
  Stop();
  stopallled();
}
