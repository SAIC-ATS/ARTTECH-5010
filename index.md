---
layout: page
title: Posts
---

<ul class="list-unstyled">
    {% for post in site.posts %}
    {% assign author = site.authors[post.author] %}
    <!-- <img class="img-circle" src="http://www.gravatar.com/avatar/{{ author.gravatar }}?s=30&d=identicon"/> -->
    <li>
        {{ post.date | date_to_string }} - {{ author.display_name }} :
        <a href="{{ site.baseurl }}{{ post.url }}">{{ post.title }}</a>
        <small><em>{{ post.tags | array_to_sentence_string }}</em></small>
    </li>
    {% endfor %}
</ul>
