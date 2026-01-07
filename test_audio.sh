#!/bin/bash
# Music debugging script for so_long

echo "=== Audio Player Availability Check ==="
echo ""

echo -n "paplay: "
which paplay &>/dev/null && echo "✓ FOUND" || echo "✗ NOT FOUND"

echo -n "ffplay: "
which ffplay &>/dev/null && echo "✓ FOUND" || echo "✗ NOT FOUND"

echo -n "mpv: "
which mpv &>/dev/null && echo "✓ FOUND" || echo "✗ NOT FOUND"

echo -n "cvlc: "
which cvlc &>/dev/null && echo "✓ FOUND" || echo "✗ NOT FOUND"

echo -n "aplay: "
which aplay &>/dev/null && echo "✓ FOUND" || echo "✗ NOT FOUND"

echo ""
echo "=== Music File Check ==="
echo ""

if [ -f "sound/music.mp3" ]; then
    echo "✓ sound/music.mp3 exists"
    echo "File size: $(du -h sound/music.mp3 | cut -f1)"
    echo "File type: $(file sound/music.mp3 | cut -d: -f2)"
else
    echo "✗ sound/music.mp3 NOT FOUND"
fi

echo ""
echo "=== Testing Audio Playback ==="
echo ""

if which ffplay &>/dev/null; then
    echo "Testing with ffplay (will auto-close)..."
    timeout 3 ffplay -nodisp -autoexit -loglevel quiet sound/music.mp3 2>&1
    [ $? -eq 0 ] && echo "✓ ffplay works!" || echo "✗ ffplay failed"
elif which mpv &>/dev/null; then
    echo "Testing with mpv (will auto-close)..."
    timeout 3 mpv --no-video --quiet sound/music.mp3 2>&1
    [ $? -eq 0 ] && echo "✓ mpv works!" || echo "✗ mpv failed"
else
    echo "No suitable audio player found for testing"
fi

echo ""
echo "=== Recommendation ==="
echo ""
echo "If no audio players are available, music won't play but the game will work fine."
echo "If you want music, install one of: ffmpeg (for ffplay), mpv, vlc (for cvlc)"
