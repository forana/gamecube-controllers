$fn = 32;

keyWidth = 20;
ledgeWidth = 2;
wallThickness = 4;
wallHeight = 9.5;
cornerRadius = 7;
wellDepth = 14;
baseThickness = 2;

holeWidth = 20;
holeHeight = 10;
holeRadius = 2.5;

module roundedRect(w, h, r) {
    translate([r, r, 0]) minkowski() {
        circle(r);
        square([w - r*2, h - r*2]);
    }
}

width = 3 * keyWidth + 2 * wallThickness;
length = 4 * keyWidth + 2 * wallThickness;
height = baseThickness + wellDepth + wallHeight;

difference() {
    // shell
    linear_extrude(0, 0, height)
        roundedRect(width, length, cornerRadius);
    // well
    translate([wallThickness + ledgeWidth, wallThickness + ledgeWidth, baseThickness])
        linear_extrude(0, 0, wellDepth + wallHeight + 1)
            square([3 * keyWidth - 2 * ledgeWidth, 4 * keyWidth - 2 * ledgeWidth]);
    // ledge
    translate([wallThickness, wallThickness, baseThickness + wellDepth])
        linear_extrude(0, 0, wallHeight + 1)
            square([3 * keyWidth, 4 * keyWidth]);
    // hole
    translate([wallThickness + ledgeWidth, wallThickness + ledgeWidth + length, baseThickness])
        rotate([90, 0, 0])
            linear_extrude(0, 0, length)
                roundedRect(holeWidth, holeHeight, holeRadius);
}
