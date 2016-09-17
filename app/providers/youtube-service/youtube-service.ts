import { Injectable } from '@angular/core';
import { Http } from '@angular/http';
import { Observable } from 'rxjs/Observable';
import 'rxjs/Rx'

@Injectable()
export class YoutubeService {
  constructor(private http: Http) { }

  load(stream: Observable<any>) {
    const BASE_URL = 'https://www.googleapis.com/youtube/v3/search';
    const API_TOKEN = 'AIzaSyD-AqEfjuN-0jHjb795G1yPg-HR8H_Xi9g';
    const makeURL = (query) => `${BASE_URL}?q=${query}&part=snippet&maxResults=10&type=video&key=${API_TOKEN}`

    return stream
      .map(inputText => makeURL(inputText) )
      //flatMap won't cancel in-flight requests, switchMap will...
      //.flatMap(url => http.get(url).map(res => res.json()))
      .switchMap(url => this.http.get(url).map(res => res.json()) )
      .map(response => response['items'] );
  }

}

