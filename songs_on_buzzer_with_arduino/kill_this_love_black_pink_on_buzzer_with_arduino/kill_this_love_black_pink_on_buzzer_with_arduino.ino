/* Play "He's A Pirate" / "Pirates of the Caribbean" Theme Song
 * By Xitang Zhao 2016.06.27
 * Youtube in Action: https://youtu.be/sjPAj1lXgtk
 * or TikTok in Action: https://www.tiktok.com/@tipstorylearn/video/6943019804261502213
 * 
 * INSTRUCTION: Hook up Pin 10 to the positive side of a buzzer or a microphone, hook up 
 * any resistor to the negative side of a buzzer (to limit current & volume & to protect the pin), 
 * and then connect the other end of the resistor to ground pin. Upload the sketch and enjoy! 
 * 
 * Don't have an Arduino right now? No worry. You can test it vitually on my TinkerCAD circuit:
 * https://www.tinkercad.com/things/f9QN4skaguI-play-pirates-of-the-caribbean-theme-song-on-buzzer
 * 
 * To learn the science of buzzer, Arduino tone library, and a step by step walkthrough of how I made this
 * Visit my learning note on TipStory: https://www.tipstory.org/learning/h2lUMccm5MeuSds
 * 
 * Last updated: 2021.03.25
 * ---------------------
 * Credits:
 * 
 * Music notes of the song obtained from Easy Music (Great website)
 * Link: http://easymusic.altervista.org/recorder-hes-a-pirate-pirates-of-caribbean-sheet-music-guitar-chords/
 * 
 * Musicnotes's "How to Read Sheet Music" Guide
 * Link: http://www.musicnotes.com/blog/2014/04/11/how-to-read-sheet-music/
 * 
 * Code inspired by Chapter 5 of Jeremy Blum's book "Exploring Arduino"
 * Link: http://www.exploringarduino.com/content/ch5/
 * 
 * Music notes' frequencies obtained from arduino website and Tone Library
 * Link: https://www.arduino.cc/en/Tutorial/toneMelody
 * Link: https://github.com/bhagman/Tone
 * 
 */

// Define pin 10 for buzzer, you can use any other digital pins (Pin 0-13)
const int buzzer = A0;

// Change to 0.5 for a slower version of the song, 1.25 for a faster version
const float songSpeed = 1.0;

// Defining frequency of each music note
#define NOTE_D3 147
#define NOTE_C4 262
#define NOTE_D4 294
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_G4 392
#define NOTE_A4 440
#define NOTE_B4 494
#define NOTE_C5 523
#define NOTE_D5 587
#define NOTE_D_black_5 622
#define NOTE_E5 659
#define NOTE_F5 698
#define NOTE_G5 784
#define NOTE_A_black_5 830
#define NOTE_A5 880
#define NOTE_B5 988
#define NOTE_D6 1175

#define rest 10

// Music notes of the song, 0 is a rest/pulse
int notes[] = {
    NOTE_D3,0,NOTE_D5,0,NOTE_D5,0,NOTE_D5,0,
    0,NOTE_D5,0,NOTE_D5,0,NOTE_D5,0,
    NOTE_D5,0,NOTE_D5,0,NOTE_D5,0,NOTE_D_black_5,0,
    NOTE_A5,0,NOTE_D5,0,NOTE_D_black_5,0,NOTE_A5,0,
   
    NOTE_D3,0,NOTE_D5,0,NOTE_D5,0,NOTE_D5,0,
    0,NOTE_D5,0,NOTE_D5,0,NOTE_D5,0,
    NOTE_D5,0,NOTE_D5,0,NOTE_A5,0,NOTE_A_black_5,0,
    NOTE_D5,0,NOTE_A5,0,NOTE_A_black_5,0,NOTE_D5,0,

    NOTE_D3,0,NOTE_D5,0,NOTE_D5,0,NOTE_D5,0,
    0,NOTE_D5,0,NOTE_D5,0,NOTE_D5,0,
    NOTE_D5,0,NOTE_D5,0,NOTE_D5,0,NOTE_D_black_5,0,
    NOTE_A5,0,NOTE_D5,0,NOTE_D_black_5,0,NOTE_A5,0,
   
    NOTE_D3,0,NOTE_D5,0,NOTE_D5,0,NOTE_D5,0,
    0,NOTE_D5,0,NOTE_D5,0,NOTE_D5,0,
    NOTE_D5,0,NOTE_D5,0,NOTE_A5,0,NOTE_A_black_5,0,
    NOTE_D5,0,NOTE_A5,0,NOTE_A_black_5,0,NOTE_D5,

    NOTE_F5,0,NOTE_F5,0,NOTE_F5,0,NOTE_F5,0,
    NOTE_F5,0,NOTE_F5,0,NOTE_F5,0,NOTE_F5,0,NOTE_F5,0,
    NOTE_E5,0,NOTE_E5,0,NOTE_D5,0,

    NOTE_F5,0,NOTE_F5,0,NOTE_F5,0,NOTE_F5,0,
    NOTE_F5,0,NOTE_F5,0,NOTE_F5,0,NOTE_F5,0,NOTE_F5,0,
    NOTE_E5,0,NOTE_E5,0,NOTE_D5,0,

    NOTE_F5,0,NOTE_F5,0,NOTE_F5,0,NOTE_F5,0,
    NOTE_F5,0,NOTE_F5,0,NOTE_D6,0,

    NOTE_F5,0,NOTE_F5,0,NOTE_F5,0,NOTE_F5,0,
    NOTE_F5,0,NOTE_F5,0,NOTE_D6,0,

    NOTE_F5,0,NOTE_F5,0,NOTE_F5,0,NOTE_F5,0,
    NOTE_F5,0,NOTE_F5,0,NOTE_D6,0,
    
    NOTE_D5,0,NOTE_E5,0,NOTE_F5,0,NOTE_F5,0,
    NOTE_E5,0,NOTE_E5,0,NOTE_D5,0,

    NOTE_F5,0,NOTE_F5,0,NOTE_F5,0,
    NOTE_F5,0,NOTE_F5,0,NOTE_F5,0,
    NOTE_F5,0,NOTE_F5,0,NOTE_F5,0,NOTE_F5,0,
    NOTE_E5,0,NOTE_E5,0,NOTE_E5,0,NOTE_D5,0,
    NOTE_F5,0,NOTE_F5,0,NOTE_D5,0,NOTE_F5,0,NOTE_F5,0,
    NOTE_D5,0,NOTE_F5,0,

    NOTE_D5,0,NOTE_D5,0,NOTE_E5,0,NOTE_F5,0,
    NOTE_D5,0,NOTE_E5,0,NOTE_F5,0,
    NOTE_D5,0,

    NOTE_F5,0,NOTE_F5,0,NOTE_F5,0,
    NOTE_F5,0,NOTE_F5,0,NOTE_F5,0,
    NOTE_F5,0,NOTE_F5,0,NOTE_F5,0,

    NOTE_A5,0,
    NOTE_F5,0,NOTE_F5,0,NOTE_F5,0,
    NOTE_A5,0,
    NOTE_F5,0,NOTE_F5,0,NOTE_F5,0,NOTE_F5,0,

    NOTE_A5,0,NOTE_F5,0,NOTE_F5,0,NOTE_D5,0,
    NOTE_F5,0,NOTE_F5,0,NOTE_D5,0,
    NOTE_F5,0,NOTE_F5,0,NOTE_D5,0,
    NOTE_F5,0,NOTE_F5,0,NOTE_D5,0,
    NOTE_F5,0,NOTE_F5,0,NOTE_D5,0,

    NOTE_E5,0,NOTE_E5,0,NOTE_E5,0,
    NOTE_F5,0,NOTE_F5,0,NOTE_D5,0,
    NOTE_G5,0,NOTE_G5,0,
    NOTE_A5,0,
    NOTE_F5,0,

//    NOTE_D5,0,NOTE_F5,0,NOTE_F5,0,

    
};
// Durations (in ms) of each music note of the song
// Quarter Note is 250 ms when songSpeed = 1.0
int durations[] = {
    50,40,375,rest,125,rest,450,rest,
    70,375,rest,125,rest,450,70,
    375,rest,125,rest,175,rest,175,rest,
    175,rest,175,rest,175,rest,50,5,

    30,40,375,rest,125,rest,450,rest,
    70,375,rest,125,rest,450,70,
    375,rest,125,rest,175,rest,175,rest,
    175,rest,175,rest,175,rest,175,5,

    50,40,375,rest,125,rest,450,rest,
    70,375,rest,125,rest,450,70,
    375,rest,125,rest,175,rest,175,rest,
    175,rest,175,rest,175,rest,50,5,

    30,40,375,rest,125,rest,450,rest,
    70,375,rest,125,rest,450,70,
    375,rest,125,rest,175,rest,175,rest,
    175,rest,175,rest,175,rest,175,

    375,rest,125,rest,375,rest,125,50,
    450,rest,375,rest,125,rest,375,rest,125,rest,
    375,rest,125,rest,450,50,

    375,rest,125,rest,375,rest,125,50,
    450,rest,375,rest,125,rest,375,rest,125,rest,
    375,rest,125,rest,450,50,

    375,rest,125,rest,375,rest,125,50,
    375,rest,125,rest,450,rest,

    375,rest,125,rest,375,rest,125,50,
    375,rest,125,rest,450,rest,

    375,rest,125,rest,375,rest,125,50,
    375,rest,125,rest,450,rest,

    375,rest,125,rest,375,rest,125,rest,
    375,rest,125,rest,450,100,

    150,rest,150,rest,150,rest,
    150,rest,150,rest,150,rest,
    375,150,150,rest,150,rest,150,rest,
    150,rest,150,rest,150,rest,375,150,
    150,rest,150,rest,150,rest,150,rest,150,rest,
    150,rest,450,70,

    150,rest,150,rest,150,rest,150,rest,
    150,rest,150,rest,150,rest,
    450,rest,

    150,rest,150,rest,150,rest,
    150,rest,150,rest,150,rest,
    150,rest,150,rest,150,rest,

    450,rest,
    150,rest,150,rest,150,rest,
    450,rest,
    150,rest,150,rest,150,rest,150,rest,

    450,rest,150,rest,150,rest,150,rest,
    150,rest,150,rest,150,rest,
    150,rest,150,rest,150,rest,
    150,rest,150,rest,150,rest,
    150,rest,150,rest,150,rest,

    150,rest,150,rest,150,rest,
    150,rest,150,rest,150,rest,
    150,rest,150,rest,
    150,rest,
    150,rest,

//    375,rest,100,rest,100,rest,
    
    
};
void setup()
{
  const int totalNotes = sizeof(notes) / sizeof(int);
  // Loop through each note
  for (int i = 0; i < totalNotes; i++)
  {
    const int currentNote = notes[i];
    float wait = durations[i] / songSpeed;
    // Play tone if currentNote is not 0 frequency, otherwise pause (noTone)
    if (currentNote != 0)
    {
      tone(buzzer, notes[i], wait); // tone(pin, frequency, duration)
    }
    else
    {
      noTone(buzzer);
    }
    // delay is used to wait for tone to finish playing before moving to next loop
    delay(wait);
  }
}

void loop()
{
  // Nothing in loop. Music only plays once.
  // You can click reset on Arduino to replay the song.
}
