local vp = {
  {0.5, 0.5, -0.5},
  {0.5, -0.5, -0.5},
  {0.5, 0.5, 0.5},
  {0.5, -0.5, 0.5},
  {-0.5, 0.5, -0.5},
  {-0.5, -0.5, -0.5},
  {-0.5, 0.5, 0.5},
  {-0.5, -0.5, 0.5},
}

return {
  {vp[7][1], vp[7][2], vp[7][3],  0, 1, 0,  1, 1,  1, 1, 1, 1},
  {vp[5][1], vp[5][2], vp[5][3],  0, 1, 0,  1, 0,  1, 1, 1, 1},
  {vp[1][1], vp[1][2], vp[1][3],  0, 1, 0,  0, 0,  1, 1, 1, 1}, -- orange OK
  {vp[3][1], vp[3][2], vp[3][3],  0, 1, 0,  0, 1,  1, 1, 1, 1},
  {vp[7][1], vp[7][2], vp[7][3],  0, 1, 0,  1, 1,  1, 1, 1, 1},
  {vp[1][1], vp[1][2], vp[1][3],  0, 1, 0,  0, 0,  1, 1, 1, 1},

  -- 4 3 7 8
  {vp[7][1], vp[7][2], vp[7][3],  0, 0, 1,  0, 1,  1, 1, 1, 1}, -- red
  {vp[3][1], vp[3][2], vp[3][3],  0, 0, 1,  1, 1,  1, 1, 1, 1}, -- 1
  {vp[4][1], vp[4][2], vp[4][3],  0, 0, 1,  1, 0,  1, 1, 1, 1}, -- 2
  {vp[8][1], vp[8][2], vp[8][3],  0, 0, 1,  0, 0,  1, 1, 1, 1}, -- 3
  {vp[7][1], vp[7][2], vp[7][3],  0, 0, 1,  0, 1,  1, 1, 1, 1}, -- 4
  {vp[4][1], vp[4][2], vp[4][3],  0, 0, 1,  1, 0,  1, 1, 1, 1}, -- 5

  -- 8 7 5 6
  {vp[5][1], vp[5][2], vp[5][3],  -1, 0, 0,  0, 1,  1, 1, 1, 1}, -- green
  {vp[7][1], vp[7][2], vp[7][3],  -1, 0, 0,  1, 1,  1, 1, 1, 1},
  {vp[8][1], vp[8][2], vp[8][3],  -1, 0, 0,  1, 0,  1, 1, 1, 1},
  {vp[6][1], vp[6][2], vp[6][3],  -1, 0, 0,  0, 0,  1, 1, 1, 1},
  {vp[5][1], vp[5][2], vp[5][3],  -1, 0, 0,  0, 1,  1, 1, 1, 1},
  {vp[8][1], vp[8][2], vp[8][3],  -1, 0, 0,  1, 0,  1, 1, 1, 1},

  -- 6 2 4 8
  {vp[4][1], vp[4][2], vp[4][3],  0, -1, 0,  0, 1,  1, 1, 1, 1},
  {vp[2][1], vp[2][2], vp[2][3],  0, -1, 0,  1, 1,  1, 1, 1, 1},
  {vp[6][1], vp[6][2], vp[6][3],  0, -1, 0,  1, 0,  1, 1, 1, 1}, -- blue OK
  {vp[8][1], vp[8][2], vp[8][3],  0, -1, 0,  0, 0,  1, 1, 1, 1},
  {vp[4][1], vp[4][2], vp[4][3],  0, -1, 0,  0, 1,  1, 1, 1, 1},
  {vp[6][1], vp[6][2], vp[6][3],  0, -1, 0,  1, 0,  1, 1, 1, 1},

  -- 2 1 3 4
  {vp[3][1], vp[3][2], vp[3][3],  1, 0, 0,  0, 1,  1, 1, 1, 1}, -- white
  {vp[1][1], vp[1][2], vp[1][3],  1, 0, 0,  1, 1,  1, 1, 1, 1},
  {vp[2][1], vp[2][2], vp[2][3],  1, 0, 0,  1, 0,  1, 1, 1, 1},
  {vp[4][1], vp[4][2], vp[4][3],  1, 0, 0,  0, 0,  1, 1, 1, 1},
  {vp[3][1], vp[3][2], vp[3][3],  1, 0, 0,  0, 1,  1, 1, 1, 1},
  {vp[2][1], vp[2][2], vp[2][3],  1, 0, 0,  1, 0,  1, 1, 1, 1},

  -- 6 5 1 2
  {vp[1][1], vp[1][2], vp[1][3],  0, 0, -1,  0, 1,  1, 1, 1, 1},
  {vp[5][1], vp[5][2], vp[5][3],  0, 0, -1,  1, 1,  1, 1, 1, 1},
  {vp[6][1], vp[6][2], vp[6][3],  0, 0, -1,  1, 0,  1, 1, 1, 1}, -- yellow OK
  {vp[2][1], vp[2][2], vp[2][3],  0, 0, -1,  0, 0,  1, 1, 1, 1},
  {vp[1][1], vp[1][2], vp[1][3],  0, 0, -1,  0, 1,  1, 1, 1, 1},
  {vp[6][1], vp[6][2], vp[6][3],  0, 0, -1,  1, 0,  1, 1, 1, 1},
}
