PRAGMA foreign_keys = ON;

CREATE TABLE scores(
  score_id   INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
  course VARCHAR(64) NOT NULL,  
  score INTEGER NOT NULL, 
  slope_rating REAL NOT NULL, 
  course_rating REAL NOT NULL,
  handicap REAL NOT NULL, 
);