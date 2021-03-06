/*
    Rocaloid
    Copyright (C) 2015 StarBrilliant <m13253@hotmail.com>

    This program is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 3.0 of the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this program.  If not,
    see <http://www.gnu.org/licenses/>.
*/

#ifndef RUCE_OPTION_MANAGER_HPP
#define RUCE_OPTION_MANAGER_HPP

#include <vector>
#include <cmath>
#include <cstdint>
#include <libwintf8/u8str.h>

namespace RUCE {

/**
 * Store global status
 */
class OptionManager {
    friend class CmdlineParser;
public:
    OptionManager();

    const WTF8::u8string &get_input_file_name() const { return input_file_name; }
    const WTF8::u8string &get_output_file_name() const { return output_file_name; }
    uint8_t get_output_pitch() const { return output_pitch; }
    double get_note_velocity() const { return note_velocity; }
    const WTF8::u8string &get_synth_flags() const { return synth_flags; }
    double get_left_blank() const { return left_blank; }
    double get_required_length() const { return required_length; }
    double get_consonant_length() const { return consonant_length; }
    double get_right_blank() const { return right_blank; }
    double get_note_volume() const { return note_volume; }
    double get_note_modulation() const { return note_modulation; }
    double get_tempo() const { return tempo; }
    double get_pitch_bend_interval() const { return 60.0/96/tempo; }
    const WTF8::u8string &get_pitch_bend_str() const { return pitch_bend_str; }
    const std::vector<double> &get_pitch_bend() const { return pitch_bend; }
    double get_pitch_bend(double seconds) const {
        if(seconds < 0)
            return 0;
        size_t index = size_t(std::floor(seconds/get_pitch_bend_interval()));
        if(index >= pitch_bend.size())
            return 0;
        return pitch_bend.data()[index];
    }

    OptionManager &set_required_length(double value) {
        required_length = value;
        return *this;
    }
    OptionManager &set_right_blank(double value) {
        right_blank = value;
        return *this;
    }
protected:
    // These are parameters passed from UTAU
    // Milliseconds are converted to seconds
    // Percents are devided by 100
    WTF8::u8string input_file_name;
    WTF8::u8string output_file_name;
    uint8_t output_pitch;
    double note_velocity;
    WTF8::u8string synth_flags;
    double left_blank;
    double required_length;  // May be adjusted later
    double consonant_length;
    double right_blank;      // May be adjusted later
    double note_volume;
    double note_modulation;
    double tempo;
    WTF8::u8string pitch_bend_str;
    std::vector<double> pitch_bend;
};

}

#endif
