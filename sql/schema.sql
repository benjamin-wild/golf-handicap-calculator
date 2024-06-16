PRAGMA foreign_keys = ON;

CREATE TABLE scores(
  owner    VARCHAR(20) NOT NULL,
  score_id   INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
  course VARCHAR(64) NOT NULL,  
  score INTEGER NOT NULL, 
  slope_rating REAL NOT NULL, 
  course_rating REAL NOT NULL, 
);