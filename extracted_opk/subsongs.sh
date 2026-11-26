mkdir -p exported_music
for i in 0 1 2 3 4 5; do
  openmpt123 --batch --subsong "$i" --force -o "/tmp/umg_sub_${i}.wav" data/music/music.it
  ffmpeg -y -loglevel error -i "/tmp/umg_sub_${i}.wav" -c:a libvorbis -q:a 4 "exported_music/track_${i}.ogg"
  rm -f "/tmp/umg_sub_${i}.wav"
done
ls -lh exported_music/