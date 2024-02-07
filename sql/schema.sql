PRAGMA foreign_keys = ON;

CREATE TABLE users(
  username VARCHAR(20)  NOT NULL,
  fullname VARCHAR(40)  NOT NULL,
  password VARCHAR(256) NOT NULL,
  handicap_index  INTEGER NOT NULL, 
  PRIMARY KEY(username)
);

CREATE TABLE scores(
  owner    VARCHAR(20) NOT NULL,
  score_id   INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
  course VARCHAR(64) NOT NULL,  
  score INTEGER NOT NULL, 
  slope_rating REAL NOT NULL, 
  course_rating REAL NOT NULL, 
  user_review TEXT,
  FOREIGN KEY(owner) REFERENCES users(username) ON DELETE CASCADE
);